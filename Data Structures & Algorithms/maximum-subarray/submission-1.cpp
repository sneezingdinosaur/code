class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr = 0;
        int maxi = nums[0];
        for(int i = 0; i<nums.size(); i++){
            if(curr<0){
                curr = 0;
            }
            curr+=nums[i];
            maxi = max(curr,maxi);
        }

        return maxi;

    }
};
