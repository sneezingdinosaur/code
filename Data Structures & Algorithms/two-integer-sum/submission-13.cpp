class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for(int i = 0; i<nums.size(); i++){
            m[nums[i]] = i;
        }
        for (int i = 0; i<nums.size(); i++){
            auto it = m.find(target-nums[i]);
            if (it != m.end() && it->second != i){
                return {i, it->second};
            }
        }
        return {};
    }
};
