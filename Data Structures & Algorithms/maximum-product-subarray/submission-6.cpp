class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minProduct = nums[0];
        int maxProduct = nums[0];
        int maxi = nums[0];

        for(int i = 1; i<nums.size(); i++){
            if(nums[i]>=0){
                minProduct = min(nums[i], minProduct*nums[i]);
                maxProduct = max(nums[i], maxProduct*nums[i]);
            }
            else{
                int temp = minProduct;
                minProduct = min(nums[i], maxProduct*nums[i]);
                maxProduct = max(nums[i], temp*nums[i]);
            }
            maxi = max(maxi, maxProduct);
        }
        return maxi;
    }
};
