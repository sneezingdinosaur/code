class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int ROWS = matrix.size();
        int COLS = matrix[0].size();

        bool rowZero = false;

        //determine which rows and columns need to be zeroed
        for(int i = 0; i < ROWS; i++){
            for(int j = 0; j<COLS; j++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    if(i==0) rowZero = true;
                    else matrix[i][0] = 0;
                }
            }
        }

        for(int i = 1; i<ROWS; i++){
            for(int j = 1; j<COLS; j++){
                if (matrix[0][j] == 0 || matrix[i][0] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        if (matrix[0][0] == 0){
            for(int i = 0; i<ROWS; i++){
                matrix[i][0] = 0;
            }
        }

        if(rowZero){
            for(int i = 0; i<COLS; i++){
                matrix[0][i] = 0;
            }
        }
    }
};
