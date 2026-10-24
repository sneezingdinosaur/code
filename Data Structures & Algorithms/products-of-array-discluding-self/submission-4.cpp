class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> out;
        vector<int> prefix(nums.size());
        vector<int> postfix(nums.size());
        prefix[0] = 1;
        postfix[nums.size()-1] = 1;
        for(int i = 1; i<nums.size(); i++){
            prefix[i] = prefix[i-1] * nums[i-1];
        }
        for(int i = nums.size()-2; i>=0; i--){
            postfix[i] = postfix[i+1] * nums[i+1];
        }
        for (int i = 0; i<nums.size(); i++){
            out.push_back(prefix[i] * postfix[i]);
        }
        return out;





        // int total = 1;
        // int nonzerototal = 1;
        // int numzeros = 0;
        // for (int i = 0; i<nums.size(); i++){
        //     if(nums[i] == 0){numzeros++;}
        //     else{nonzerototal*=nums[i];}
        //     total*=nums[i];
            
            
        // }
        // vector<int>out;
        // for(int i = 0; i<nums.size(); i++){
        //     if (nums[i]==0){
        //         if(numzeros==1){
        //             out.push_back(nonzerototal);
        //         }
        //         else{
        //             out.push_back(0);
        //         }
        //     }
        //     else{
        //         out.push_back(total/nums[i]);
        //     }
        // }
        // return out;
    }
};
