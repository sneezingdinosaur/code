#include <unordered_map>;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs){

        vector<string>sortedstrs;
        unordered_map<string,vector<int>>mappings;
        vector<vector<string>>out;

        for(int i = 0; i<strs.size(); i++){
            auto sorted = strs[i];
            sort(sorted.begin(), sorted.end());
            sortedstrs.push_back(sorted);
        }

        for(int i = 0; i<strs.size(); i++){
            if(mappings.contains(sortedstrs[i])){
                mappings[sortedstrs[i]].push_back(i);
            }
            else{
                mappings[sortedstrs[i]] = {i};
            }
        }
        int j = 0;
        for(auto& [key,value] : mappings){
            out.push_back({});
            for(int i : value){
                out[j].push_back(strs[i]);
            }
            j++;
        }
        
        return out;
    }
};
