class Solution {
public:

    vector<vector<int>> mappings;

    int dfs(int idx, int prevIdx, vector<int> &nums){
        if(idx == nums.size()){return 0;}

        if(mappings[idx][prevIdx+1] != -1) return mappings[idx][prevIdx+1];
        
        int p1 = dfs(idx+1, prevIdx, nums);
        int p2 = 0;
        if(prevIdx == -1 || nums[idx] > nums[prevIdx]){
            p2 = 1 + dfs(idx+1, idx, nums);
        }

        return mappings[idx][prevIdx+1] = max(p1,p2);
    }

    int lengthOfLIS(vector<int>& nums) {
        mappings.assign(nums.size(), vector<int>(nums.size()+1, -1));
        return dfs(0, -1, nums);
    }
};
