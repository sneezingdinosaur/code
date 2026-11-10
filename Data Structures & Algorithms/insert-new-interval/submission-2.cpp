class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ret;
        int newStart = newInterval[0];
        int newEnd = newInterval[1];
        bool added = false;

        for(vector<int> interval : intervals){
            int start = interval[0];
            int end = interval[1];

            if(added){ret.push_back(interval); continue;}

            if(newEnd>=start && newStart<=end){
                newStart = min(newStart, start);
                newEnd = max(newEnd, end);
                
                newInterval[0] = newStart;
                newInterval[1] = newEnd;
            }
            else if(end<newStart){
                ret.push_back(interval);
            }
            else if(start>newEnd){
                ret.push_back(newInterval);
                ret.push_back(interval);
                added = true;
            }
        }

        if(!added){ret.push_back(newInterval);}
        return ret;
    }
};
