class Solution {
public:

    int dfs(int idx, string &s, vector<int>&memo){
        if(idx == s.size()) return 1;
        if(s[idx] == '0') return 0;
        if(memo[idx] != -1) return memo[idx];

        int ways = 0;

        if(idx+1<s.size() && (s[idx] == '1' || (s[idx] == '2' && s[idx+1] <= '6'))){
            ways += dfs(idx+2, s, memo);
        }
        ways += dfs(idx+1, s, memo);
        memo[idx] = ways;

        return ways;
    }

    int numDecodings(string s) {
        vector<int>memo(s.size(), -1);
        return dfs(0, s, memo);
    }
};
