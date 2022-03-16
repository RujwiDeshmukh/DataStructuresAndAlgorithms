class Solution {
public:
    int maxProfit(vector<int>& prices) {
     
        
        int n = prices.size();
        int minPrice=INT_MAX;
        int maxProfit=0;  //it is taken 0 as profit cannot be negative
        
        for(int i=0;i<n;i++)
        {
            minPrice = min(minPrice,prices[i]);
            maxProfit = max(maxProfit, prices[i]-minPrice);
        }
        return maxProfit;
    }
};