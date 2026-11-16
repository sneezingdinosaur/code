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
        if(intervals.size()==0) return 0;
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){
            if(a.start == b.start){
                return a.end<b.end;
            }
            return a.start<b.start;
        });

        int latest = intervals[0].end;
        int rooms = 1;
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i = 1; i<intervals.size(); i++){
            if(latest>intervals[i].start){
                if(pq.size() == 0 || pq.top()>intervals[i].start){
                    rooms++;
                }
                else{
                    pq.pop();
                }
                pq.push(intervals[i].end);
            }
            else{
                latest = intervals[i].end;
            }
        }

        return rooms;
    }
};
