class Solution {
public:    
    vector<vector<int>> threeSum(vector<int>& nums) {
        bool flip = true;
        set<vector<int>>out;
        vector<vector<int>>ret;

        sort(nums.begin(), nums.end());
        for (int i = 0; i<nums.size(); i++){
            int k = 0; int j = nums.size()-1;
            while(j>k){
                if(j == i){
                    j--;
                    continue;
                }
                if(k == i){
                    k++;
                    continue;
                }
                int result = -1*(nums[j] + nums[k]);
                if(result == nums[i]){
                    vector<int>temp = {nums[i],nums[k],nums[j]};
                    sort(temp.begin(), temp.end());
                    out.insert(temp);
                    k++; j--;
                }
                else if (result > nums[i]){
                    k++;
                }
                else{
                    j--;
                }
            }
        }
        for(vector<int>x : out){
            ret.push_back(x);
        }
        return ret;
    }
};
