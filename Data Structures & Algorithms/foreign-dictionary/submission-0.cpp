class Solution {
public:
    //char mapped to the list of things it is smaller than
    unordered_map<char, vector<char>> mappings;
    //keep track of all chars and remove chars maybe?
    unordered_set<char> chars;

    unordered_set<char> visited;
    unordered_set<char> inPath;
    string res;

    bool dfs(char c){
        if (inPath.contains(c)) return false;
        if (visited.contains(c)) return true;

        inPath.insert(c);
        for(char p : mappings[c]){
            if (!dfs(p)) return false;
        }
        inPath.erase(c);

        visited.insert(c);
        res+=c;
        return true;
    }

    string foreignDictionary(vector<string>& words) {
        string prev = words[0];

        for(char c : prev){
            chars.insert(c);
        }
        
        for(int i = 1; i<words.size(); i++){
            for(char c : words[i]){
                chars.insert(c);
            }

            int j = 0;

            for(j = 0; j<words[i].size(); j++){
                if (j<prev.size()){
                    if(prev[j] != words[i][j]){
                        mappings[words[i][j]].push_back(prev[j]);
                        break;
                    }
                }

            }
            if (j==words[i].size() && prev.size()>words[i].size()){return "";}
            prev = words[i];
        }

        for(char c : chars){
            if(!dfs(c)) return "";
        }
        return res;
        
    }
};
