class Solution {
public:

    int help(vector<int>&nums){
        int rob1 = 0;
        int rob2 = 0;
        for(int n : nums){
            int temp = max(rob1+n, rob2);
            rob1 = rob2;
            rob2 = temp;
        }
        return rob2;
    }

    int rob(vector<int>& nums) {
        if(nums.size()==1){return nums[0];}

        vector<int>nums1 (nums.begin()+1, nums.end());
        vector<int>nums2 (nums.begin(), nums.end()-1);

        return max(help(nums1), help(nums2));


    }
};
