class Solution {
public:
    vector<vector<int>>mappings;

    int dfs(int x, int y, int &m, int &n){
        if(x==m-1){return 1;}
        if(y==n-1){return 1;}

        if(mappings[x][y]!=-1){return mappings[x][y];}

        return mappings[x][y] = dfs(x+1, y, m, n) + dfs(x, y+1, m, n);
    }

    int uniquePaths(int m, int n) {
        mappings.assign(m, vector<int>(n,-1));
        return dfs(0,0,m,n);
    }
};
