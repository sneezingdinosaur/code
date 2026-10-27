class Solution {
public:
    string minWindow(string s, string t) {
        int need[128] = {0};
        for(char c : t) need[c]++;
        int missing = t.size();
        int left = 0;
        int bestStart = 0;
        int bestLen = INT_MAX;

        for(int right = 0; right<s.size(); right++){
            if(need[s[right]] > 0){
                missing--;
            }
            need[s[right]]--;
            while(missing == 0){
                if(right - left + 1 < bestLen){bestLen = right - left + 1; bestStart = left;}
                need[s[left]]++;
                if(need[s[left]] > 0){
                    missing++;
                }
                left++;
            }
        }
        if (bestLen == INT_MAX){return "";}
        else {return s.substr(bestStart, bestLen);}
    }
};
