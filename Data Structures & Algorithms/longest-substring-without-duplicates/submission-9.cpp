class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>temp;
        unordered_map<char, int>mappings;
        int maxi = 0;
        int window = 0;
        int i = 0;
        char multi;
        while(i+window<s.size()){
            temp.insert(s[i + window]);
            mappings[s[i + window]]++;
            if(temp.size() == window + 1){
                window++;
                maxi = max(window,maxi);
            }
            else{
                if(mappings[s[i]]==1){
                    temp.erase(s[i]);
                }
                mappings[s[i]]--;
                i++;
            }
        }
        return maxi;
    }
};
