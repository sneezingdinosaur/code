class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>filtered;
        for(int i = 0; i<nums.size(); i++){
            filtered.insert(nums[i]);
        }
        int maxi = 0;
        int counter = 1;
        vector<int>starts;
        for(int n : filtered){
            if (!filtered.contains(n-1)){
                starts.push_back(n);
            }
        }
        for(int n : starts){
            while(filtered.contains(n+1)){
                n++;
                counter++;
            }
            maxi = max(maxi, counter);
            counter = 1;
        }
        return maxi;
    }
};
