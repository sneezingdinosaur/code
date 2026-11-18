class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {        
        for (int i = 0; i<tasks.size(); i++){
            tasks[i].push_back(i);
        }

        sort(tasks.begin(),tasks.end());

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        vector<int>res;
        int i = 0;
        int time = tasks[0][0];
        
        while(!pq.empty() || i<tasks.size()){
            while (i<tasks.size() && time >= tasks[i][0]){
                pq.push({tasks[i][1], tasks[i][2]});
                i++;
            }

            if (pq.empty()){
                time = tasks[i][0];
            }
            else{
                pair<int,int> temp = pq.top();
                pq.pop();
                time+=temp.first;
                res.push_back(temp.second);
            }
        }
        return res;
    }
};