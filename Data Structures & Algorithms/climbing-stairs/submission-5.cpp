class Solution {
public:

    int fb(int n, int n1, int n2){
        if(n==0){return n1+n2;}
        int temp = n1;
        n1+=n2;
        return fb(n-1, n1, temp);
    }

    int climbStairs(int n) {
        if(n==1){return 1;}
        if(n==2){return 2;}

        return fb(n-2, 1,1);
    }
};
