class Solution {

struct Node{
    set<Node*>prereqs;
    set<Node*>prereqsOf;
    int val;
    int prereqsLeft = 0;
};



public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        queue<Node*>q;
        unordered_map<int, Node*> mappings;
        vector<int> out;
        

        for(int i = 0; i<numCourses; i++){
            mappings[i] = new Node();
            mappings[i]->val = i;
        }

        for(int i = 0; i<prerequisites.size(); i++){
            mappings[prerequisites[i][0]]->prereqs.insert(mappings[prerequisites[i][1]]);
            mappings[prerequisites[i][1]]->prereqsOf.insert(mappings[prerequisites[i][0]]);
            mappings[prerequisites[i][0]]->prereqsLeft = mappings[prerequisites[i][0]]->prereqs.size();
        }

        for(auto &a : mappings){
            if(a.second->prereqsLeft == 0){
                q.push(a.second);
            }
        }

        while(!q.empty()){
            Node* temp = q.front();
            for(Node* prereq : temp->prereqsOf){
                prereq->prereqsLeft--;
                if(prereq->prereqsLeft <= 0){
                    q.push(prereq);
                }
            }
            out.push_back(temp->val);
            q.pop();
        }

        if(out.size() == numCourses) return out;
        return {};



    }
};
