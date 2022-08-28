class Solution {
public:
    
    vector<int> countDigits(int n)
    {
        vector<int>digit(10);
        //as maximum of 10 digits can be there in the power of 2 
        //within the range of n which is 10^9
        //storing freq of each digit in an array
        
        while(n)
        {
            digit[n%10]++;
            n = n/10;
        }
        
        return digit;
    }
    
   // https://leetcode.com/problems/reordered-power-of-2/discuss/1120216/Reordered-Power-of-2-or-Short-and-Easy-w-Explanation-or-Beats-100
    
    bool reorderedPowerOf2(int n) {
        
        vector<int>digits = countDigits(n);
        
         int pow = 1;
         for(int i=0;i<30;i++)
         {
             if(countDigits(pow)==digits)
             {
                 return true;
             }
             
             pow = pow<<1;
         }
    
        return false;
    }
};