class Solution {
public:

    unordered_map<int, bool>mappings;

    bool dfs(int idx, string &s, vector<string> &wordDict){
        if (idx==s.size()){return true;}
        if(mappings.contains(idx)){
            return mappings[idx];
        }

        for(string word : wordDict){
            if(s.substr(idx,word.size()) == word){
                
                mappings[idx] = dfs(idx+word.size(), s, wordDict);

                if (mappings[idx]) {
                    return true;
                }
            }
        }

        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        return dfs(0, s, wordDict);
    }
};
