class Solution {
private:
    struct Course {
        int val;
        unordered_set<Course*> prereqs;
        unordered_set<Course*> prereqOf;
    };




public:
    unordered_map<int, Course*>created;
    unordered_set<int>found;
    unordered_set<int>needed;
    unordered_map<int, int> remaining;

    void dfs (Course* root){
        if (found.contains(root->val)) return;
        found.insert(root->val);
        for(Course* n : root->prereqOf){
            if (--remaining[n->val] == 0) dfs(n);
        }
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.size()==0){return true;}

        for(int i = 0; i<prerequisites.size(); i++){
            Course* node = new Course();
            if(!created.contains(prerequisites[i][0])){
                node->val = prerequisites[i][0];
                created[node->val] = node;
            }
            Course* node1 = new Course();
            if(!created.contains(prerequisites[i][1])){
                node1->val = prerequisites[i][1];
                created[node1->val] = node1;
            }

            created[prerequisites[i][1]]->prereqOf.insert(created[prerequisites[i][0]]);
            created[prerequisites[i][0]]->prereqs.insert(created[prerequisites[i][1]]);
        }

        for (auto& [v, c] : created) remaining[v] = c->prereqs.size();

        for(int i = 0; i<numCourses; i++){
            if(created.contains(i)){
                if (created[i]->prereqs.size()==0){
                    dfs(created[i]);
                }
                needed.insert(i);
            }
        }
        
        cout<<needed.size();
        cout<<found.size();

        for (auto& x : needed) {
            if (!found.contains(x)) return false;
        }
        return true;
    }
};
