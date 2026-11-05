class Solution {
public:
    void dfs(int i, int j, vector<vector<bool>>& reach, vector<vector<int>>& heights) {
        if (reach[i][j]) return;
        reach[i][j] = true;
        int m = heights.size(), n = heights[0].size();
        if (i != 0   && heights[i][j] <= heights[i-1][j]) dfs(i-1, j, reach, heights);
        if (j != 0   && heights[i][j] <= heights[i][j-1]) dfs(i, j-1, reach, heights);
        if (i != m-1 && heights[i][j] <= heights[i+1][j]) dfs(i+1, j, reach, heights);
        if (j != n-1 && heights[i][j] <= heights[i][j+1]) dfs(i, j+1, reach, heights);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pac(m, vector<bool>(n, false));
        vector<vector<bool>> atl(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            dfs(i, 0, pac, heights);      // left edge
            dfs(i, n-1, atl, heights);    // right edge
        }
        for (int j = 0; j < n; j++) {
            dfs(0, j, pac, heights);      // top edge
            dfs(m-1, j, atl, heights);    // bottom edge
        }

        vector<vector<int>> out;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (pac[i][j] && atl[i][j]) out.push_back({i, j});
        return out;
    }
};