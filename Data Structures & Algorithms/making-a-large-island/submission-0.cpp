class Solution {
public:

    unordered_map<int, int> mappings;

    int dfs(int i, int j, int islandId, vector<vector<int>>& grid){
        if(i<0 || j<0 || j==grid[0].size() || i == grid.size()){return 0;}
        if(grid[i][j] != 1){return 0;}

        grid[i][j] = islandId;

        return 1 + dfs(i-1, j, islandId, grid) + dfs(i+1, j, islandId, grid) + dfs(i, j-1, islandId, grid) + dfs(i, j+1, islandId, grid);
    }

    int largestIsland(vector<vector<int>>& grid) {
        mappings[0] = 0;
        int maximum = 1;
        int islandId = 2;
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                    mappings[islandId] = dfs(i, j, islandId, grid);
                    maximum = max(mappings[islandId], maximum);
                    islandId++;
                }
            }
        }
        
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(grid[i][j] == 0){
                    unordered_set<int>visited;
                    int total = 1;
                    if(i>0 && !visited.contains(grid[i-1][j])){
                        total+=mappings[grid[i-1][j]];
                        visited.insert(grid[i-1][j]);
                    }
                    if(j>0 && !visited.contains(grid[i][j-1])){
                        total+=mappings[grid[i][j-1]];
                        visited.insert(grid[i][j-1]);
                    }
                    if(i!=grid.size()-1 && !visited.contains(grid[i+1][j])){
                        total+=mappings[grid[i+1][j]];
                        visited.insert(grid[i+1][j]);
                    }
                    if(j!=grid[0].size()-1 && !visited.contains(grid[i][j+1])){
                        total+=mappings[grid[i][j+1]];
                        visited.insert(grid[i][j+1]);
                    }
                    maximum = max(maximum, total);
                }
            }
        }

        return maximum;
    }
};
