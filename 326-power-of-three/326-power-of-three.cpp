class Solution {
public:
    bool isPowerOfThree(int n) {
        
        if(n==0)
        {
            return false;
        }
        
        if(n==1)
        {
            return true;
        }
        
        double f1 = log10(n);
        double f2 = log10(3);
        
        cout<<f1<<endl;
        cout<<f2<<endl;
        
        
        cout<<(f1/f2)<<endl;
        
        
        double ans = double(f1/f2);
        
        cout<<ans<<endl;
        
       // int f3 = log10(n);
        // int f4 = log10(3);
        
        //f4 value is 0.477121 so int value will be 0
        //bt if its double data type then it will as it is
        
     //   int ans1 = f3/f4;
        
      //  cout<<floor(ans1)<<endl;
        // cout<<ceil(ans1)<<endl;
        
        if(floor(ans)==ceil(ans))
                 
           {
            //cout<<floor(log(n)/log(3))<<endl;
            //cout<<ceil(log(n)/log(3))<<endl;
               return true;
           }
        

        
           return false;
    }
};