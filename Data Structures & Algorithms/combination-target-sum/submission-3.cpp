class Solution {
public:
    void help (int remain, vector<int>& track, int i, vector<int>& nums, vector<vector<int>>& ret){
        
        if(remain==0){ret.push_back(track); return;}
        if(i==nums.size() || nums[i]>remain){return;}
        
        track.push_back(nums[i]);
        help(remain-nums[i], track, i, nums, ret);
        track.pop_back();
        help(remain, track, i+1, nums, ret);
    }


    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        vector<int> track;
        help(target, track, 0, nums, ret);
        return ret;
    }
};
