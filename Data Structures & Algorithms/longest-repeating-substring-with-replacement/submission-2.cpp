class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0;
        int window = k;
        int maxi = 0;
        int count[26] = {0};

        for(int j = 0; j<window+1; j++){
            count[s[j]-'A']++;
        }

        while(i+window<s.size()){
            int max1 = 0;
            for(int j = 0; j<26; j++){
                max1 = max(max1, count[j]);
            }
            if(window+1-max1 > k){
                count[s[i]-'A']--;
                i++;
                if (i + window < s.size()) {
                    count[s[i + window] - 'A']++;
                }
            }
            else{
                maxi = max(maxi, window+1);
                window++;
                if (i + window < s.size()) {
                    count[s[i + window] - 'A']++;
                }
            }
        }
        return maxi;
    }
};
