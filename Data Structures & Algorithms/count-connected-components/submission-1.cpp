class Solution {
//unionfind implementation 
public:

    vector<int> par;
    vector<int> rank;

    int find(int node){
        int result = node;

        while(result != par[result]){
            par[result] = par[par[result]];
            result = par[result];
        }

        return result;
    }

    int unions(int node1, int node2){
        int par1 = find(node1);
        int par2 = find(node2);
        if (par1 == par2){
            return 0;
        }
        if (rank[par2]> rank[par1]){
            par[par1] = par2;
            rank[par2] += rank[par1];
        }
        else{
            par[par2] = par1;
            rank[par1] += rank[par2];
        }
        return 1;
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        for (int i = 0; i<n; i++){
            par.push_back(i);
            rank.push_back(1);
        }
        for(int i = 0; i<edges.size(); i++){
            n-=unions(edges[i][0], edges[i][1]);
        }
        return n;


    }
};
