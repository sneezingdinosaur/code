class Solution {
public:
    unordered_map<char, unordered_set<char>> mappings;
    unordered_map<char, bool> visited; //false = visited, true = current path
    vector<char> result;

    bool dfs(char c){
        if (visited.contains(c)){
            return visited[c];
        }
        visited[c] = true;

        for (char neighbor : mappings[c]){
            if (dfs(neighbor)) return true;
        }

        visited[c] = false;
        result.push_back(c);
        return false;
    }


    string foreignDictionary(vector<string>& words) {
        for (string s : words)
            for (char c : s)
                mappings[c]; 

        for(int i = 0; i+1<words.size(); i++){
            string w1 = words[i];
            string w2 = words[i+1];
            int minLen = min(w1.size(), w2.size());
            if (w1.size()>w2.size() && w1.substr(0, minLen) == w2.substr(0, minLen)) return "";
            for(int j = 0; j<minLen; j++){
                if(w1[j]!=w2[j]){
                    mappings[w1[j]].insert(w2[j]);
                    break;
                }
            }
        }

        for (const auto &c : mappings){
            if (dfs(c.first)) return "";
        }

        return string(result.rbegin(), result.rend());

    }
};
