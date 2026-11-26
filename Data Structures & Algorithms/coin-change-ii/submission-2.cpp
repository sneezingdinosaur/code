class Solution {
public:

    int count = 0;
    vector<vector<int>> memo;

    long long help(int amount, vector<int>&coins, int idx){
        if (amount == 0) return 1;
        if (idx == coins.size() || amount<0) return 0;
        if(memo[idx][amount] != -1) return memo[idx][amount];

        return memo[idx][amount] = help(amount-coins[idx], coins, idx) + help(amount, coins, idx+1);
    }

    int change(int amount, vector<int>& coins) {
        memo.assign(coins.size(), vector<int>(amount + 1, -1));
        return help(amount,coins, 0);
    }
};
