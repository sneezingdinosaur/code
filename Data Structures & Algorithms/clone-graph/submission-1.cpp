/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

    unordered_map<int, Node*>clones;

    void help (Node* node, Node* copy){
        for (Node* n : node->neighbors){
            if(!clones.contains(n->val)){
                clones[n->val] = new Node(n->val);
                help(n, clones[n->val]);
            }
            copy->neighbors.push_back(clones[n->val]);
        }
    }

    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        Node* copy = new Node(1);
        help(node, copy);
        return copy;
    }
};
