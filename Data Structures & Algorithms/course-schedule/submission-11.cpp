class Solution {

public:

    unordered_set<int> visitSet;
    unordered_map <int, vector<int>> preMap;

    bool dfs(int course){
        if(visitSet.contains(course)) return false;
        if (preMap[course].empty()) return true;

        visitSet.insert(course);
        for (int pre : preMap[course]){
            if (!dfs(pre)) return false;
        }

        visitSet.erase(course);
        preMap[course] = {};

        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i = 0; i<prerequisites.size(); i++){
            preMap[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for (int i = 0; i<numCourses; i++){
            if(!dfs(i)) return false;
        }
        return true;
    }
};
