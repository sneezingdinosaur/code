class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        vector<vector<int>>dp (coins.size(), vector<int>(amount+1,-1));
        
        //dp[i][j] = minimum # of coins
        for(int i = 0; i<coins.size(); i++){
            dp[i][0] = 0;
            for(int j = 0; j<=amount; j++){
                if(i>0){
                    dp[i][j] = dp[i-1][j];
                }
                if(j>=coins[i] && dp[i][j-coins[i]] != -1){
                    int candidate = dp[i][j-coins[i]] + 1;

                    if(dp[i][j] == -1){
                        dp[i][j] = candidate;
                    }
                    else{
                        dp[i][j] = min(dp[i][j], candidate);
                    }
                }

            }

        }

        return dp[coins.size()-1][amount];
    }
};
