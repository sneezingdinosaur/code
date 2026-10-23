class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = -101;
        for(int i = 0; i<prices.size(); i++){
            for(int j = i+1; j<prices.size();j++){
                if (j<i){break;}
                if (prices[j]-prices[i]>maxi){maxi = prices[j] - prices[i];}
            }
        }



        // int maxi = -101;
        // for(int i = 0; i<prices.size(); i++){
        //     for(int j = i+1; j<prices.size(); j++){
        //         if (prices[j]-prices[i]>maxi){maxi = prices[j] - prices[i];}
        //     }
        // }

        return max(0,maxi);
    }
};
