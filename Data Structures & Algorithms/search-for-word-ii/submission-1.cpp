class Solution {
private:
    struct TrieNode{
        unordered_map<char, TrieNode*>children;
        bool isEnd = false;
    };
public:
    vector<string>solutions;
    void dfs(TrieNode* root, int i, int j, string str, vector<vector<char>>& board){
        int n = board.size();

        if(root->isEnd){solutions.push_back(str); root->isEnd = false;}

        if(i>=n || i<0 || j>=board[0].size() || j<0){return;}
        char c = board[i][j];

        if(!root->children.count(c)){return;}

        str += c; 
        board[i][j] = '#';

        dfs(root->children[c], i+1, j, str, board);
        dfs(root->children[c], i, j+1, str, board);
        dfs(root->children[c], i-1, j, str, board);
        dfs(root->children[c], i, j-1, str, board);

        board[i][j] = c;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for(string s : words){
            TrieNode* curr = root;
            for(char c : s){
                if(!curr->children.count(c)){
                    curr->children[c] = new TrieNode();
                }
                curr = curr->children[c];
            }
            curr->isEnd = true;
        }

        for(int i = 0; i<board.size(); i++){
            for(int j = 0; j<board[i].size(); j++){
                dfs(root, i, j, "", board);
            }
        }

        return solutions;
    }
};
