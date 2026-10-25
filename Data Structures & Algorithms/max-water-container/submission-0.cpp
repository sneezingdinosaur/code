class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0; int j = heights.size()-1;
        int maxi = 0;
        while(i!=j){
            int height = min(heights[i],heights[j]);
            maxi = max(maxi, (j-i)*height);
            if(height == heights[i]){
                i++;
            }
            else{
                j--;
            }
        }
        return maxi;
    }
};
