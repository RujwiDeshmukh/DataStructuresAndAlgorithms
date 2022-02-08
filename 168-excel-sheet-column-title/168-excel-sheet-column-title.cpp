class Solution {
public:
    string convertToTitle(int columnNumber) {
        
        //version of converting binary to decimal 
        //and decimal to binary
        
        string res="";
        int n = columnNumber;
        
        while(n > 0)
        {
            char rem = 'A' + (n-1)%26;
            //n-1 as we had already added A to the remainder
            //so 1 count is already added to it
            res += rem;
            
            n = (n-1)/26;
        }
        
        reverse(res.begin(),res.end());
        
        return res;
        
    }
};