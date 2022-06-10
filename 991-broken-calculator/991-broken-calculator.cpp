class Solution {
public:
    int brokenCalc(int startValue, int target) {
        
        int result=0;
        
        while(startValue < target)
        {
            //entering while loop means performing 1 operation already
            //so incrementing the result
            result++;
            cout<<result<<endl;
            if(target%2 == 0)
            {
                target = target/2;
            }
            else
            {
                target = target+1;
            }
        }
        
        //now startValue has become greater than target 
        //then we have to increment target by adding 1 to it everytime
        //so calculating the difference between target and startValue
        result = result+(startValue-target);
        
        return result;
    }
};