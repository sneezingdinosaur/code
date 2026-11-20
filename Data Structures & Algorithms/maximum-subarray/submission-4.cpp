class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr = 0;
        int maxi = nums[0];
        int i = 0;
        while(i<nums.size()){
            if(curr<0){
                curr = 0;
            }
            curr+=nums[i];
            maxi = max(maxi, curr);
            i++;
        }
        return maxi;
    }
};
