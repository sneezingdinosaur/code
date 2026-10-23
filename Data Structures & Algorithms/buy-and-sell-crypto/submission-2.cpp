class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0; int r = 1;
        int maxP = 0;
        while(r<prices.size()){
            if (prices[l]<prices[r]){
                maxP = max(maxP, prices[r]-prices[l]);
            }
            else{l = r;}
            r++; 
        }
        return maxP;



        // int maxi = -101;
        // for(int i = 0; i<prices.size(); i++){
        //     for(int j = i+1; j<prices.size(); j++){
        //         if (prices[j]-prices[i]>maxi){maxi = prices[j] - prices[i];}
        //     }
        // }

        // return max(0,maxi);
    }
};
