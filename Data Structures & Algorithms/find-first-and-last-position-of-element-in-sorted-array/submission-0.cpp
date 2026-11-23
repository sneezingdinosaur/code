class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        int m;

        int base = -1;

        while(l<=r){
            m = (l+r)/2;
            if (nums[m]==target){
                base = m; break;
            } 
            if (nums[m]>target){
                r = m-1;
            }
            if(nums[m]<target){
                l = m+1;
            }
        }

        if(base == -1) return {-1,-1};

        vector<int> out(2, base);

        l = 0;
        r = base;

        while(l<=r){
            m = (r + l)/2;
            if(nums[m] == target){
                if(m == 0 || nums[m-1] != target){
                    out[0] = m; break;
                }
                else{
                    r = m-1;
                }
            }
            else{
                l = m+1;
            }
        }

        l = base;
        r = nums.size()-1;

        while(l<=r){
            m = (r + l)/2;
            if(nums[m] == target){
                if(m == nums.size()-1 || nums[m+1] != target){
                    out[1] = m; break;
                }
                else{
                    l = m+1;
                }
            }
            else{
                r = m-1;
            }
        }

        return out;
    }
};