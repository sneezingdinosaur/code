class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1){return nums[0];}

        int maxNotN = nums[0];
        int maxN = nums[1];
        

        for(int i = 2; i<nums.size(); i++){
            int temp = maxN;
            maxN = max(maxNotN+nums[i], maxN);
            maxNotN = max(maxNotN,temp);
        }

        return max(maxNotN,maxN);
    }
};
