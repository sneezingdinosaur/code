class Solution {
public:
    void dfs(int i, int j, bool &atl, bool &pac, vector<vector<int>> &heights, vector<vector<bool>> &visited){
        if(i<=0 || j<=0){pac = true;}
        if(i>=heights.size()-1 || j>=heights[0].size()-1){atl = true;}
        
        if(pac && atl){return;}

        visited[i][j] = true;

        if(i!=0 && heights[i][j] >= heights[i-1][j] && !visited[i-1][j]){dfs(i-1,j,atl,pac,heights, visited);}
        if(i!=heights.size()-1 && heights[i][j] >= heights[i+1][j] && !visited[i+1][j]){dfs(i+1,j,atl,pac,heights, visited);}
        if(j!=0 && heights[i][j] >= heights[i][j-1] && !visited[i][j-1]){dfs(i,j-1,atl,pac,heights, visited);}
        if(j!=heights[0].size()-1 && heights[i][j] >= heights[i][j+1] && !visited[i][j+1]){dfs(i,j+1,atl,pac,heights, visited);}
        
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> out;
        for(int i = 0; i<heights.size(); i++){
            for(int j = 0; j<heights[0].size();j++){
                bool atl = false; bool pac = false;
                vector<vector<bool>> visited(heights.size(), vector<bool>(heights[0].size(), false));
                dfs(i,j, atl, pac, heights, visited);
                if(atl && pac) out.push_back({i,j});
            }
        }
        return out;
    }
};
