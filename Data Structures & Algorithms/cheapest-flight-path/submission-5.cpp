class Solution {
public:

    unordered_map<int, vector<pair<int, int>>>mappings;
    vector<vector<int>> memo;

    int big = 1000000;

    int dfs(int src, int &dst, int cost, int curr, int k){
        if(src == dst){return cost;}
        if(curr == k+1){return big;}

        if(memo[src][curr]!=-1){return cost + memo[src][curr];}

        int mini = big;
        
        for(pair<int,int> p : mappings[src]){
            mini = min(mini, dfs(p.first, dst, cost + p.second, curr+1, k));
            memo[src][curr] = mini;
        }

        return mini;
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        memo.assign(n, vector<int>(k+2, -1));
        for(int i = 0; i<flights.size(); i++){
            mappings[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        int ret = dfs(src, dst, 0, 0, k);
        if (ret == big) return -1;
        return ret;
    }
};
