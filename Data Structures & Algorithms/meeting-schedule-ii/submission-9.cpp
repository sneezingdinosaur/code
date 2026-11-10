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

        sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b){
            if(a.start==b.start){
                return a.end<b.end;
            }
            return a.start<b.start;
        });

        priority_queue<int, vector<int>, greater<int>>latestRooms;

        int latest = intervals[0].end;

        int rooms = 1;

        for(int i = 1; i<intervals.size(); i++){
            if(intervals[i].start < latest){
                if(latestRooms.size() == 0 || intervals[i].start<latestRooms.top()){
                    rooms++;
                    latestRooms.push(intervals[i].end);
                }
                else{
                    int temp = latestRooms.top();
                    latestRooms.pop();
                    latestRooms.push(max(temp, intervals[i].end));
                }
            }
            else latest = intervals[i].end;
            
        }

        return rooms;
        
    }
};
