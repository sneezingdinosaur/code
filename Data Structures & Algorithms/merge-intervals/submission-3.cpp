class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 1){return intervals;}

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> out;
        vector<int>prev = intervals[0];

        for(int i = 1; i<intervals.size(); i++){
            vector<int>interval = intervals[i];

            if(interval[0] > prev[1]){
                out.push_back(prev);
                prev = interval;
            }

            else if(interval[1] < prev[0]){
                out.push_back(interval);
                prev = interval;
            }

            else{
                prev[0] = min(interval[0], prev[0]);
                prev[1] = max(interval[1], prev[1]);
            }
        }

        out.push_back(prev);
        return out;
    }
};
