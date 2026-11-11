class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> out;

        int top = 0;
        int left = 0;
        int bottom = matrix.size();
        int right = matrix[0].size();

        while(top<bottom && left<right){
            //get every i in the top row
            for(int i = left; i<right; i++){
                out.push_back(matrix[top][i]);
            }
            top++;
            //get every i in right column
            for(int i = top; i<bottom; i++){
                out.push_back(matrix[i][right-1]);
            }
            right--;

            if(left>=right || top>=bottom) break;

            //get every i in bottom row
            for(int i = right-1; i>=left; i--){
                out.push_back(matrix[bottom-1][i]);
            }
            bottom--;
            //get every i in the left column
            for(int i = bottom-1; i>=top; i--){
                out.push_back(matrix[i][left]);
            }
            left++;
        }

        return out;
    }
};
