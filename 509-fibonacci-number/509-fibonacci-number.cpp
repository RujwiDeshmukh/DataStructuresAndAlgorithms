class Solution {
public:
    int fib(int n) {
        
          int x0=0, x1=1;
          int x2=0;
          int temp;
          int sum=0;
        
          if(n <= 1)
          {
              return n;
          }
        
          for(int i=0;i<n-1;i++)
          {
              x2 = x0+x1;
              temp=x1;
              x1=x2;
              x0=temp;
          }
        
          return x2;
    }
};