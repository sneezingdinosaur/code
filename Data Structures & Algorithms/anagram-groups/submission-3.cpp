#include <unordered_map>;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs){
        map<array<int,26>,vector<string>>mappings;
        vector<vector<string>> output;
        
        for(int i = 0; i<strs.size(); i++){
            array<int,26>characters {};
            for(char c : strs[i]){
                characters[c-'a']++;
            }
            mappings[characters].push_back(strs[i]);
        }

        for(auto& [key,value] : mappings){
            output.push_back(value);
        }

        return output;


        // vector<string>sortedstrs;
        // unordered_map<string,vector<int>>mappings;
        // vector<vector<string>>out;

        // for(int i = 0; i<strs.size(); i++){
        //     auto sorted = strs[i];
        //     sort(sorted.begin(), sorted.end());
        //     sortedstrs.push_back(sorted);
        // }

        // for(int i = 0; i<strs.size(); i++){
        //     if(mappings.contains(sortedstrs[i])){
        //         mappings[sortedstrs[i]].push_back(i);
        //     }
        //     else{
        //         mappings[sortedstrs[i]] = {i};
        //     }
        // }
        // int j = 0;
        // for(auto& [key,value] : mappings){
        //     out.push_back({});
        //     for(int i : value){
        //         out[j].push_back(strs[i]);
        //     }
        //     j++;
        // }
        
        // return out;
    }
};
