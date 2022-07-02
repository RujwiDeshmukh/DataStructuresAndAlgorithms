class Solution {
public:
    
    int getArea(int param, vector<int>& param_array)
    {
          sort(param_array.begin(),param_array.end());
        
          int size = param_array.size();
        
          int maxVal = max(param_array[0],param-param_array[size-1]);
               
          for(int i=1;i<size;i++)
          {
              maxVal = max(maxVal, param_array[i]-param_array[i-1]);
          }
        
        cout<<maxVal<<endl;
        return maxVal;
        
    }
    
    
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        return (int)((long)getArea(h, horizontalCuts)*getArea(w, verticalCuts)%1000000007);
    }
};