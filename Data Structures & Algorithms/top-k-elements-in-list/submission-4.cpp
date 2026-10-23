#include <unordered_map>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>>arr (n+1);
        unordered_map<int, int>mappings;
        for(int i : nums){
            mappings[i]++;
        }
        for(auto& [key,value] : mappings){
            arr[value].push_back(key);
        }
        vector<int> out;
        for(int i = n; i>=0; i--){
            for (int j : arr[i]){
                out.push_back(j);
                if(out.size()==k){
                    return out;
                }
            }
        }

        return out;











        // unordered_map<int, int>mappings;
        
        // for(int i : nums){
        //     mappings[i]++;
        // }

        // priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        // for (auto& [key,value] : mappings){
        //     if (pq.size()<k){
        //         pq.push({value, key});
        //     }
        //     else{
        //         if(value>pq.top().first){
        //             pq.pop();
        //             pq.push({value,key});
        //         }
        //     }
        // }
        // vector <int> out;
        // while(!pq.empty()){
        //     out.push_back(pq.top().second);
        //     pq.pop();
        // }

        

        // return out;
    }
};
