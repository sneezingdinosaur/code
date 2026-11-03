class Solution {
public:

    bool help(int i, int j, int idx, string curr, vector<vector<char>> board, string &word){
        if(i < 0 || j < 0 || i >= board.size() || j>= board[0].size()){return false;}
        curr += board[i][j];
        if(curr == word){return true;}
        if(board[i][j] != word[idx]){return false;}
        char c = board[i][j];
        board[i][j] = '#';
        return help(i+1, j, idx+1, curr, board, word) || help(i, j+1, idx+1, curr, board, word) || help(i-1, j, idx+1, curr, board, word) || help(i, j-1, idx+1, curr, board, word);
        board[i][j] = c;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i<board.size(); i++){
            for(int j = 0; j<board[0].size(); j++){
                if(board[i][j] == word[0]){
                    if (help(i, j, 0, "", board, word)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
