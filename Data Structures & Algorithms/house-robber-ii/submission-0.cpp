class Solution {
public:

    vector<vector<int>> dp;

    int help(int begin, vector<int>& nums, bool first){
        if(begin>=nums.size()){return 0;}
        if(begin+1==nums.size() && first){return 0;}

        //false = 0 true = 1
        if (dp[begin][first] != -1) {
            return dp[begin][first];
        }

        int rob;
        if(begin == 0){
            rob = nums[begin] + help(begin+2, nums, true);
        }
        else{
            rob = nums[begin] + help(begin+2, nums, first);
        }
        int skip = help(begin+1, nums, first);

        dp[begin][first] = max(rob,skip);

        return dp[begin][first];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        dp.assign(n, vector<int>(2, -1));
        return help(0,nums, false);
    }
};
