class Solution {
public:
    vector<vector<int>> result;
    vector<int> curr;

    void dfs(int i, int total, int &target, vector<int> &nums){
        if(total == target){
            result.push_back(curr);
            return;
        }
        if(i>=nums.size() || total>target){
            return;
        }
        curr.push_back(nums[i]);
        total+=nums[i];
        dfs(i, total, target, nums);
        curr.pop_back();
        total-=nums[i];
        dfs(i+1, total, target, nums);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
        dfs(0, 0, target, nums);
        return result;
    }
};
