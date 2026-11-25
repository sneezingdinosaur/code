class Solution {

public:

    unordered_map<int,vector<int>> mappings;
    unordered_set<int>visited;

    bool dfs(int i){
        if (visited.contains(i)) return false;
        if (mappings[i].empty()) return true;

        visited.insert(i);

        for(int prereq : mappings[i]){
            if(!dfs(prereq)) return false;
        }

        visited.erase(i);
        mappings[i] = {};
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i = 0; i<numCourses; i++){
            mappings[i] = {};
        }

        for(int i = 0; i<prerequisites.size(); i++){
            mappings[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        for(int i = 0; i<numCourses; i++){
            if(!dfs(i)) return false;
        }

        return true;
        
    }
};
