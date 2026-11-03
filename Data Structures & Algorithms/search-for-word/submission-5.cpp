class Solution {
public:

    bool dfs(int r, int c, int idx, string &word, vector<vector<char>> board){
        if (idx == word.size()) return true;
        if(r<0 || c<0 || r>=board.size() || c>= board[0].size() || board[r][c] != word[idx]) return false;
        char ch = board[r][c];
        board[r][c] = '#';
        return dfs(r+1, c, idx+1, word, board) || dfs(r-1, c, idx+1, word, board) || dfs(r, c+1, idx+1, word, board) || dfs(r, c-1, idx+1, word, board);
        board[r][c] = ch;

    }

    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i<board.size(); i++){
            for(int j = 0; j<board[0].size(); j++){
                if (dfs(i, j, 0, word, board)) return true;
            }
        }
        return false;
    }
};
