class Solution {
public:
    unordered_map<Node*,Node*>clones;

    Node* dfs (Node* node){
        if(clones.contains(node)){
            return clones[node];
        }

        Node* copy = new Node(node->val);
        clones[node] = copy;
        for(Node* n : node->neighbors){
            copy->neighbors.push_back(dfs(n));
        }
        return copy;
    }
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        return dfs(node);
    }
};