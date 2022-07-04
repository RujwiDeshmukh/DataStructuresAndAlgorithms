class Solution {
public:
    int candy(vector<int>& ratings) {
        
        int n = ratings.size();
        int i=1;
        int candy=n;
        
        while(i<n)
        {
            if(ratings[i] == ratings[i-1])
            {
                i++;
                continue;
            }
            
            //for increasing slope
            
            int peak=0;
            
            while(ratings[i] > ratings[i-1])
            {
                peak++;
                candy += peak;
                i++;
                
                if(i==n)
                {
                    return candy;  //for case [1,2]
                }
            }
            
            int valley=0;
            
            while(i<n && ratings[i] < ratings[i-1])
            {
                valley++;
                candy += valley;
                i++;
            }
            
            candy -= min(peak,valley);
        }
        return candy;
    }
};