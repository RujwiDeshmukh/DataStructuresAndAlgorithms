class Solution {
public:
    int countEven(int num) {
        
        int cnt=0;
        
        for(int i=1;i<=num;i++)
        {
            int currNum = i;
            int sum=0;
            
            while(currNum > 0)
            {
                int rem = currNum%10;
                currNum = currNum/10;
                sum += rem;
            }
            
            if(sum%2==0)
            {
                cnt++;
            }
        }
        
        return cnt;
    }
};