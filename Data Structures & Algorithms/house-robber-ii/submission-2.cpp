class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1){return nums[0];}

        vector<int>nums1(nums.begin()+1, nums.end());
        vector<int>nums2(nums.begin(), nums.end()-1);

        int rob11 = 0;
        int rob12 = 0;
        for(int n : nums1){
            int temp = max(rob11+n, rob12);
            rob11 = rob12;
            rob12 = temp;
        }

        int rob21 = 0;
        int rob22 = 0;
        for(int n : nums2){
            int temp = max(rob21+n, rob22);
            rob21 = rob22;
            rob22 = temp;
        }


        return max(rob12, rob22);


    }
};
