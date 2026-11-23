class Solution {
public:

    struct Node{
        unordered_set<Node*> prereqs;
        unordered_set<Node*> prereqsOf;
        int val;
        int prereqsLeft;
    };

    unordered_set<int> visited;
    unordered_map<int, Node*> mappings;

    void dfs(Node* root){
        visited.insert(root->val);

        for(Node* next : root->prereqsOf){
            next->prereqsLeft--;
            if(next->prereqsLeft == 0){
                dfs(next);
            }
        }
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i = 0; i<numCourses; i++){
            mappings[i] = new Node();
            mappings[i]->val = i;
        }

        for(int i = 0; i<prerequisites.size(); i++){
            mappings[prerequisites[i][0]] -> prereqs.insert(mappings[prerequisites[i][1]]);
            mappings[prerequisites[i][0]] -> prereqsLeft = mappings[prerequisites[i][0]] -> prereqs.size();
            mappings[prerequisites[i][1]] -> prereqsOf.insert(mappings[prerequisites[i][0]]);
        }

        for(auto& a : mappings){
            if (a.second->prereqs.empty()){
                dfs(a.second);
            }
        }

        return visited.size() == numCourses;
    }
};
