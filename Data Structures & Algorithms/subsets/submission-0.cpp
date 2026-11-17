class Solution {
public:
    vector<vector<int>> ret;

    void add(int i, vector<int> curr, vector<int>& nums){
        if(i == nums.size()){
            ret.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        add(i+1, curr, nums);
        curr.pop_back();
        add(i+1, curr, nums);
    }



    vector<vector<int>> subsets(vector<int>& nums) {
        add(0, {}, nums);
        return ret;
    }
};
