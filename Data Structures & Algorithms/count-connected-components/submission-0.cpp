class Solution {
public:
    unordered_set<int>visited;
    unordered_set<int>notVisited;
    unordered_map<int, vector<int>>mappings;

    void dfs(int root){
        visited.insert(root);
        notVisited.erase(root);
        if(mappings[root].size()==0) return;
        for(int n : mappings[root]){
            if(!visited.contains(n)){
                dfs(n);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        for(int i = 0; i<n; i++){
            notVisited.insert(i);
        }

        for(int i = 0; i<edges.size(); i++){
            mappings[edges[i][0]].push_back(edges[i][1]);
            mappings[edges[i][1]].push_back(edges[i][0]);
        }

        int count = 0;

        while(!notVisited.empty()){
            int val = *notVisited.begin();
            dfs(val);
            count+=1;
        }

        return count;
    }
};
