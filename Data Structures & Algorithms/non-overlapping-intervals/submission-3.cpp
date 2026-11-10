class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int prevSecond = 50001;
        int erase = -1;


        for(vector<int>interval : intervals){
            if(interval[0]>=prevSecond){
                prevSecond = interval[1];
                continue;
            }
            else{
                erase++;
                prevSecond = min(prevSecond, interval[1]);
            }
        }

        return erase;
    }
};
