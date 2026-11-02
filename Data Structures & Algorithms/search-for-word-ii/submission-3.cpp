class Solution {
private:
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        bool isEnd = false;
    };

    unordered_set<string> result;   // like Python's res = set()
    vector<vector<bool>> visit;     // like Python's visit = set(), as a grid
    int ROWS, COLS;

    void dfs(int r, int c, TrieNode* node, string word, vector<vector<char>>& board) {
        if (r < 0 || c < 0 || r == ROWS || c == COLS ||
            visit[r][c] || !node->children.count(board[r][c])) {
            return;
        }

        visit[r][c] = true;
        node = node->children[board[r][c]];
        word += board[r][c];
        if (node->isEnd) {
            result.insert(word);
        }

        dfs(r - 1, c, node, word, board);
        dfs(r + 1, c, node, word, board);
        dfs(r, c - 1, node, word, board);
        dfs(r, c + 1, node, word, board);
        visit[r][c] = false;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (const string& s : words) {
            TrieNode* curr = root;
            for (char c : s) {
                if (!curr->children.count(c)) {
                    curr->children[c] = new TrieNode();
                }
                curr = curr->children[c];
            }
            curr->isEnd = true;
        }

        ROWS = board.size();
        COLS = board[0].size();
        result.clear();
        visit.assign(ROWS, vector<bool>(COLS, false));

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                dfs(r, c, root, "", board);
            }
        }

        return vector<string>(result.begin(), result.end());
    }
};