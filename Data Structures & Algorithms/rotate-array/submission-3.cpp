class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int shift = k%nums.size();
        vector<int>tmp;
        vector<int>tmp2;
        for(int i = nums.size()-shift; i<nums.size(); i++){
            tmp.push_back(nums[i]);
        }
        for(int i = 0; i<nums.size()-shift; i++){
            tmp2.push_back(nums[i]);
        }
        for(int i = 0; i<nums.size()-shift; i++){
            nums[i+shift] = tmp2[i];
        }
        for(int i = 0; i<shift; i++){
            nums[i] = tmp[i];
        }
    }
};