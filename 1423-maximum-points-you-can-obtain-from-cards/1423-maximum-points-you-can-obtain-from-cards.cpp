class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
     
        int start=0 ,end=0;
        int sum = 0;
        int totalSum =0;
        int size = cardPoints.size()-k;
        int res = INT_MAX;
//here we are considering the window of cards which are not considered
//not considered card sum will be minimum so that considered cards sum will be maximum
        
        totalSum = accumulate(cardPoints.begin(),cardPoints.end(),0);
        
        if(size==0)
        {
            return totalSum;
        }
        
        totalSum =0;
        
        while(end < cardPoints.size())
        {
            sum+= cardPoints[end];
            totalSum += cardPoints[end];
            if(end-start+1 < size)
            {
                end++;
                continue;
            }
            
            
            if(end-start+1 == size)
            {
                res = min(res,sum);
                sum -= cardPoints[start];
                start++;
                end++;
            }
        }
        return (totalSum - res);
    }
};