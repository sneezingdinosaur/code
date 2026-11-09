class Solution {
public:
    vector<vector<int>>mappings;
    vector<vector<bool>>calculated;

    int dfs(int x, int y, int &m, int &n){
        if(x==m-1){return 1;}
        if(y==n-1){return 1;}

        // if(mappings[x][y]!=-1 && !calculated[x][y]){calculated[x][y] = true; return mappings[x][y];}
        if(mappings[x][y]!=-1){return mappings[x][y];}

        return mappings[x][y] = dfs(x+1, y, m, n) + dfs(x, y+1, m, n);
    }

    int uniquePaths(int m, int n) {
        mappings.assign(m+1, vector<int>(n+1,-1));
        calculated.assign(m+1, vector<bool>(n+1,false));
        return dfs(0,0,m,n);
    }
};
