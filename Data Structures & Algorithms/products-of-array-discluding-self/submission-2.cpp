class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int total = 1;
        int nonzerototal = 1;
        int numzeros = 0;
        for (int i = 0; i<nums.size(); i++){
            if(nums[i] == 0){numzeros++;}
            else{nonzerototal*=nums[i];}
            total*=nums[i];
            
            
        }
        vector<int>out;
        for(int i = 0; i<nums.size(); i++){
            if (nums[i]==0){
                if(numzeros==1){
                    out.push_back(nonzerototal);
                }
                else{
                    out.push_back(0);
                }
            }
            else{
                out.push_back(total/nums[i]);
            }
        }
        return out;
    }
};
