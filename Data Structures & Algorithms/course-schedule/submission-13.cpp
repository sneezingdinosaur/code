class Solution {
public:
    unordered_set<int> visitSet;
    unordered_map<int,vector<int>> preMap;

    bool dfs(int course){
        if(visitSet.contains(course)) return false;
        if(preMap[course].empty()) return true;

        visitSet.insert(course);
        for(int prereq : preMap[course]){
            if (!dfs(prereq)) return false;
        }

        visitSet.erase(course);
        preMap[course] = {};

        return true;
    }


    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        
        for(int i = 0; i<numCourses; i++){
            preMap[i] = {};
        }

        for(vector<int> prereq : prerequisites){
            preMap[prereq[0]].push_back(prereq[1]);
        }

        for(int i = 0; i<numCourses; i++){
            if(!dfs(i)) return false;
        }

        return true;
    }
};
