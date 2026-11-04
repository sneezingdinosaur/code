class Solution {
public:

    

    void travel (int i, int j, vector<vector<char>>& grid){
        if(i<0 || j<0 || j>=grid[0].size() || i>=grid.size()){return;}
        if(grid[i][j]=='1'){
            grid[i][j] = '#';
            travel(i+1,j,grid);
            travel(i-1,j,grid);
            travel(i,j+1,grid);
            travel(i,j-1,grid);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int total = 0;
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(grid[i][j]=='1'){
                    travel(i, j, grid);
                    total++;
                }
            }
        }
        
        return total;
    }
};
