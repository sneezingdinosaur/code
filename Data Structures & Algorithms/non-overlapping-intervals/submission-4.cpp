class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int prevEnd = intervals[0][1];
        int erase = 0;

        for(int i = 1; i<intervals.size(); i++){
            vector<int> interval = intervals[i];

            if(interval[0]>=prevEnd){
                prevEnd = interval[1];
            }
            else{
                erase++;
                prevEnd = min(prevEnd, interval[1]);
            }
        }

        return erase;
    }
};
