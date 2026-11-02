class Solution {
public:
    vector<vector<int>> result;

    void dfs(int i, vector<int> &curr, int total, int &target, vector<int> &nums){
        if(total == target){
            result.push_back(curr);
            return;
        }
        if(i>=nums.size() || total>target){
            return;
        }
        curr.push_back(nums[i]);
        total+=nums[i];
        dfs(i, curr, total, target, nums);
        curr.pop_back();
        total-=nums[i];
        dfs(i+1, curr, total, target, nums);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> curr;
        dfs(0, curr, 0, target, nums);
        return result;
    }
};
