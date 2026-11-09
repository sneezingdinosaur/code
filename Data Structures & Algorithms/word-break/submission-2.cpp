class Solution {
public:

    unordered_map<string, bool>mappings;

    bool dfs(string s, vector<string> &wordDict){
        if (s.size()==0){return true;}

        for(string word : wordDict){
            if(s.substr(0,word.size()) == word){
                string updated = s.substr(word.size(),s.size()-word.size());
                if(mappings.contains(updated)){
                    if(mappings[updated]) return true;
                    continue;
                }


                mappings[updated] = dfs(updated, wordDict);

                if (mappings[updated]) {
                    return true;
                }
            }
        }

        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        return dfs(s, wordDict);
    }
};
