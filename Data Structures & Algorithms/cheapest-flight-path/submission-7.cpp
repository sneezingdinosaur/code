class Solution {
public:

    unordered_map<int, vector<pair<int,int>>> mappings;
    vector<vector<int>> memo;

    int dfs(int src, int &dst, int cost, int tally, int &k){
        if(src == dst) return cost;
        if(tally == k+1) return 1000000;

        int mini = 1000000;

        if(memo[src][tally] != -1) return cost + memo[src][tally];

        for(pair<int,int> p : mappings[src]){
            mini = min(mini, dfs(p.first, dst, cost+p.second, tally+1, k));
        }

        memo[src][tally] = mini;
        return mini;
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        memo.assign(n+1, vector<int>(k+1, -1));

        for(int i = 0; i<n; i++){
            mappings[i] = {};
        }

        for(int i = 0; i<flights.size(); i++){
            mappings[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }

        int cost = dfs(src, dst, 0, 0, k);
        if(cost == 1000000) return -1;
        return cost;
    }
};
