class Solution {
public:

    unordered_map<int, int>idxs;
    int help(int begin, vector<int>& nums){
        if(begin>=nums.size()){return 0;}

        if (idxs.count(begin)) {
            return idxs[begin];
        }

        int rob = nums[begin] + help(begin+2, nums);
        int skip = help(begin+1, nums);

        idxs[begin] = max(rob,skip);

        return max(rob,skip);
    }

    int rob(vector<int>& nums) {
        return help(0,nums);
    }
};
