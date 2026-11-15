class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>prices(n, 1000000);
        prices[src] = 0;

        for(int i = 0; i<k+1; i++){
            vector<int>tmpPrices = prices;

            for(vector<int>flight : flights){
                int s = flight[0];
                int d = flight[1];
                int p = flight[2];
                if (prices[s] == 1000000) continue;
                if(prices[s] + p < tmpPrices[d]){
                    tmpPrices[d] = prices[s] + p;
                }
            }
            prices = tmpPrices;
        }
        if (prices[dst] == 1000000) return -1;
        return prices[dst];
    }
};
