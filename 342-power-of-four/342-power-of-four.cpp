class Solution {
public:
    bool isPowerOfFour(int n) {
        
        if(n==0)
        {
            return false;
        }
        
        if(floor(log(n)/log(4)) == ceil(log(n)/log(4)))
        {
            return true;
        }
        
        return false;
    }
};