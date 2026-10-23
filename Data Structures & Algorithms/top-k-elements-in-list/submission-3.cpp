#include <unordered_map>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>mappings;
        for(int i : nums){
            mappings[i]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for (auto& [key,value] : mappings){
            if (pq.size()<k){
                pq.push({value, key});
            }
            else{
                if(value>pq.top().first){
                    pq.pop();
                    pq.push({value,key});
                }
            }
        }
        vector <int> out;
        while(!pq.empty()){
            out.push_back(pq.top().second);
            pq.pop();
        }

        

        return out;
    }
};
