/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int>start;
        vector<int>end;
        for(Interval interval : intervals){
            start.push_back(interval.start);
            end.push_back(interval.end);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int i = 0;
        int j = 0;

        int curr = 0;
        int maxi = 0;

        while(i!=intervals.size()){
            if(start[i] < end[j]){
                i++;
                curr++;
            }
            else{
                j++;
                curr--;
            }
            maxi = max(curr, maxi);
        }

        return maxi;
    }
};
