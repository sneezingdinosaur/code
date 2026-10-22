#include <unordered_set>
using namespace std;

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int>seen;
        for (int i = 0; i<nums.size(); i++){
            seen.insert(nums[i]);
        }
        return nums.size() != seen.size();
    }
};