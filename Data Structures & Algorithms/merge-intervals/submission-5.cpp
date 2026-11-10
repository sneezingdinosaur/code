class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> out;
        out.push_back(intervals[0]);

        for(int i = 1; i<intervals.size(); i++){
            int start = intervals[i][0];
            int end = intervals[i][1];

            int lastEnd = out.back()[1];

            if(start <= lastEnd){
                out.back()[1] = max(lastEnd, end);
            }
            else{
                out.push_back({start,end});
            }
        }

        return out;
    }
};
