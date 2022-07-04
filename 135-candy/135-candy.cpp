class Solution {
public:
    
    //https://leetcode.com/problems/candy/discuss/1301166/C%2B%2B-Solution-oror-O(n)-oror-Easy-Understanding
    
    int candy(vector<int>& ratings) {
        
        int n = ratings.size();
        
        vector<int>numbers(n,1);
        
        for(int i=1;i<n;i++)
        {
            if(ratings[i] > ratings[i-1])
            {
                numbers[i] = numbers[i-1]+1;
            }
        }
        
        int res = numbers[n-1];
        
        for(int i=n-2;i>=0;i--)
        {
            if((ratings[i] > ratings[i+1]) && (numbers[i] < numbers[i+1]+1))
            {
                numbers[i] = numbers[i+1]+1;
            }
            
            res += numbers[i];
        }
        
        return res;
    }
};