class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        
        int n = prices.size();
        vector<int>discount;
        
        for(int i=0;i<n;i++)
        {
            int flag=1;
            for(int j=i+1;j<n;j++)
            {
                 if(prices[j] <= prices[i])
                 {
                     discount.push_back(prices[i]-prices[j]);
                     flag=0;
                     break;
                 }
            }
            
            if(flag)
            {
                discount.push_back(prices[i]);
            }
        }
        
        return discount;
    }
};