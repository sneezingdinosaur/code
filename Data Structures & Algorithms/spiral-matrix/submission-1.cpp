class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        bool left = true;
        bool right = false;
        bool up = false;
        bool down = false;
        int count = 0;
        vector<int> out;
        
        int x = 0; int y = 0;
        int i = 1;

        while(out.size() != matrix.size() * matrix[0].size()){

            out.push_back(matrix[y][x]);

            //check if it hits boundary
            if (x==matrix[0].size()-i && left){
                left = false;
                down = true;
                count++;
            }
            if (y==matrix.size()-i && down){
                down = false;
                right = true;
                count++;
            }
            if (x==i-1 && right){
                right = false;
                up = true;
                count++;
            }
            if (y==i && up){
                up = false;
                left = true;
                i++;
                count++;
            }
            

            if(left){
                x++;
            }
            if(down){
                y++;
            }
            if(right){
                x--;
            }
            if(up){
                y--;
            }
        }

        return out;
        
    }
};
