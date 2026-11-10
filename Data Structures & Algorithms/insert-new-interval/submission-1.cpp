class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ret;
        bool added = false;
        int nFirst = newInterval[0];
        int nSecond = newInterval[1];

        for(vector<int> interval : intervals){
            int first = interval[0];
            int second = interval[1];

            if(added){ret.push_back(interval); continue;}

            if(second < nFirst){
                ret.push_back(interval);
            }

            else if(first > nSecond){
                ret.push_back(newInterval);
                ret.push_back(interval);
                added = true;
            }

            else{
                if(nFirst<=second){
                    newInterval[0] = min(nFirst, first);
                    nFirst = newInterval[0];
                }
                if(nSecond>=first){
                    newInterval[1] = max(nSecond, second);
                    nSecond = newInterval[1];
                }
            }
        }
        if(!added){ret.push_back(newInterval);}
        return ret;
    }
};
