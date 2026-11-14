class Solution {
public:

    unordered_map<int,vector<pair<int,int>>> mappings;
    vector<vector<int>> memo;

    int dfs(int cost, int tally, int src, int &dst, int &k){
        if(src == dst){
            return cost;
        }
        if(tally == k+1){return 1000000;}

        if(memo[src][tally] != -1){
            return cost + memo[src][tally];
        }

        int mini = 1000000;
        for(pair<int,int> destCost : mappings[src]){
            mini = min(mini, dfs(cost+destCost.second, tally+1, destCost.first, dst, k));
            memo[src][tally] = mini;
        }
        return mini;
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        memo.assign(n, vector<int>(k+2, -1));

        for(vector<int> flight : flights){
            mappings[flight[0]].push_back({flight[1], flight[2]});
        }

        int ret = dfs(0, 0, src, dst, k);
        if (ret == 1000000){return -1;}
        return ret;
    }
};
