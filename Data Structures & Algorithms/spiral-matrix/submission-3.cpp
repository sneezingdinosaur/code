class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> ordered;

        bool right = true;
        bool left = false;
        bool up = false;
        bool down = false;

        int i = 0; int j = 0;

        int m = matrix.size();
        int n = matrix[0].size();

        ordered.push_back(matrix[i][j]);
        matrix[i][j] = 101;

        while(ordered.size()!=m*n){
            if(right){
                if(j+1<n && matrix[i][j+1]!=101){
                    j++;
                    ordered.push_back(matrix[i][j]);
                    matrix[i][j] = 101;
                }
                else{
                    right = false; down = true;
                }
            }
            else if(down){
                if(i+1<m && matrix[i+1][j]!=101){
                    i++;
                    ordered.push_back(matrix[i][j]);
                    matrix[i][j] = 101;
                }
                else{
                    down = false; left = true;
                }
            }
            else if(left){
                if(j-1>=0 && matrix[i][j-1]!=101){
                    j--;
                    ordered.push_back(matrix[i][j]);
                    matrix[i][j] = 101;
                }
                else{
                    left = false; up = true; 
                }
            }
            else if(up){
                if(i-1>=0 && matrix[i-1][j]!=101){
                    i--;
                    ordered.push_back(matrix[i][j]);
                    matrix[i][j] = 101;
                }
                else{
                    up = false; right = true; 
                }
            }
        }

        return ordered;
    }
};
