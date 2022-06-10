class Solution {
public:
    int brokenCalc(int startValue, int target) {
        
       // https://leetcode.com/problems/broken-calculator/discuss/1874851/oror-C%2B%2B-oror-Easy-Approach-oror-PROPER-EXPLANATION
        
        if(startValue >= target)
        {
            return startValue - target;
        }
        
        if(target%2==0)
        {
            return 1 + brokenCalc(startValue, target/2);
        }
        
        return 1 + brokenCalc(startValue , target+1);
    }
};