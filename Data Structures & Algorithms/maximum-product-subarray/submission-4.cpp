class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==1){return nums[0];}


        int currMax = nums[0];
        int currMin = nums[0];
        int maxi = nums[0];

        for(int i = 1; i<nums.size(); i++){
            if(nums[i]>=0){
                currMax = max(nums[i], currMax*nums[i]);
                currMin = min(nums[i], currMin*nums[i]);
            }
            else{
                int temp = currMin;
                currMin = min(nums[i], currMax*nums[i]);
                currMax = max(nums[i], temp*nums[i]);
                
            }

            maxi = max(maxi, currMax);
        }
        return maxi;
    }
};
