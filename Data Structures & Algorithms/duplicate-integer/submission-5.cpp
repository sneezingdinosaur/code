#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // unordered_set<int>seen;
        // for (int i = 0; i<nums.size(); i++){
        //     seen.insert(nums[i]);
        // }
        // return nums.size() != seen.size();


        sort(nums.begin(), nums.end());
        for (int i = 1; i<nums.size(); i++){
            if (nums[i] == nums[i-1]){return true;}
        }
        return false;
    }
};