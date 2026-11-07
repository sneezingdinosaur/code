class Solution {
public:
    unordered_set<int>visited;
    unordered_map<int,unordered_set<int>> mappings;

    bool dfs(int curr, int prev, int &num){

        visited.insert(curr);
        if(visited.size() == num) return true;

        for(int n : mappings[curr]){
            if(visited.contains(n) && n!=prev){
                return false;
            }
            if(n!=prev){
                if(!dfs(n, curr, num)) return false;
            }
        }

        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if (n==1) return true;

        for(int i = 0; i<edges.size(); i++){
            mappings[edges[i][0]].insert(edges[i][1]);
            mappings[edges[i][1]].insert(edges[i][0]);
        }
        
        return dfs(0, -1, n) && visited.size()==n;
    }
};
