class Solution {
public:    
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>out;
        sort(nums.begin(), nums.end());
        int prev = 100001;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == prev){continue;}
            int target = -1*nums[i];
            int j = i+1; int k = nums.size()-1;
            int prevj = 100001; int prevk = 100001;
            while(j<k){
                if(prevj == nums[j]){j++; continue;}
                if(prevk == nums[k]){k--; continue;}

                if(nums[j] + nums[k] == target){
                    out.push_back({nums[i], nums[j], nums[k]});
                    prevj = nums[j]; prevk = nums[k];
                    j++; k--;
                }
                else if (nums[j] + nums[k] > target){
                    prevk = nums[k];
                    k--;
                }
                else{
                    prevj = nums[j];
                    j++;
                }
            }
            prev = nums[i];
        }
        return out;



    //     set<vector<int>>out;
    //     vector<vector<int>>ret;

    //     sort(nums.begin(), nums.end());
    //     for (int i = 0; i<nums.size(); i++){
    //         int k = 0; int j = nums.size()-1;
    //         while(j>k){
    //             if(j == i){
    //                 j--;
    //                 continue;
    //             }
    //             if(k == i){
    //                 k++;
    //                 continue;
    //             }
    //             int result = -1*(nums[j] + nums[k]);
    //             if(result == nums[i]){
    //                 vector<int>temp = {nums[i],nums[k],nums[j]};
    //                 sort(temp.begin(), temp.end());
    //                 out.insert(temp);
    //                 k++; j--;
    //             }
    //             else if (result > nums[i]){
    //                 k++;
    //             }
    //             else{
    //                 j--;
    //             }
    //         }
    //     }
    //     for(vector<int>x : out){
    //         ret.push_back(x);
    //     }
    //     return ret;
    // }
    }
};
