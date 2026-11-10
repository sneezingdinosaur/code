class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ret;
        int newStart = newInterval[0];
        int newEnd = newInterval[1];

        for(int i = 0; i<intervals.size(); i++){
            vector<int> interval = intervals[i];
            int start = interval[0];
            int end = interval[1];

            if(start>newEnd){
                ret.push_back(newInterval);
                ret.insert(ret.end(), intervals.begin() + i, intervals.end());
                return ret;
            }

            else if(end<newStart){
                ret.push_back(interval);
            }

            else{
                newStart = min(newStart, start);
                newEnd = max(newEnd, end);
                
                newInterval[0] = newStart;
                newInterval[1] = newEnd;
            }
        }

        ret.push_back(newInterval);
        return ret;
    }
};
