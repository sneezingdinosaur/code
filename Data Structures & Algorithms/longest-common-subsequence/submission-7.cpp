class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>mappings(text1.size()+1, vector<int>(text2.size()+1, 0));
        for(int i = text1.size()-1; i>=0; i--){
            for(int j = text2.size()-1; j>=0; j--){
                int add = 0;
                if(text1[i] == text2[j]){
                    mappings[i][j] = 1 + mappings[i+1][j+1];
                }
                else{
                    mappings[i][j] = max(mappings[i+1][j],mappings[i][j+1]);
                }
            }
        }

        return mappings[0][0];
    }
};
