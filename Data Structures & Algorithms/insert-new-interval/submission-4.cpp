
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> ret;
        ret.reserve(n + 1);

        int i = 0;
        int start = newInterval[0];
        int end = newInterval[1];

        // Add intervals before newInterval
        while (i < n && intervals[i][1] < start) {
            ret.push_back(intervals[i++]);
        }

        // Merge overlapping intervals
        while (i < n && intervals[i][0] <= end) {
            start = min(start, intervals[i][0]);
            end = max(end, intervals[i][1]);
            i++;
        }

        ret.push_back({start, end});

        // Add remaining intervals
        while (i < n) {
            ret.push_back(intervals[i++]);
        }

        return ret;
    }
};
