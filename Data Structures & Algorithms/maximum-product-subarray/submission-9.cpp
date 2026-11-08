class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minProduct = 1;
        int maxProduct = 1;
        int maximum = *max_element(nums.begin(), nums.end());

        for(int i = 0; i<nums.size(); i++){
            if(nums[i]==0){
                maxProduct = 1;
                minProduct = 1;
                continue;
            }
            int temp = maxProduct*nums[i];
            maxProduct = max({nums[i], maxProduct*nums[i], minProduct*nums[i]});
            minProduct = min({nums[i], temp, minProduct*nums[i]});

            maximum = max(maximum, maxProduct);
        }
        return maximum;
    }
};
