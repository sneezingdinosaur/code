class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int shift = k%nums.size();
        for(int i = 0; i<k; i++){
            int prev = nums[0];
            int last = nums[nums.size()-1];
            for(int j = 1; j<nums.size(); j++){
                int temp = nums[j];
                nums[j] = prev;
                prev = temp;
            }
            nums[0] = last;
        }
    }
};