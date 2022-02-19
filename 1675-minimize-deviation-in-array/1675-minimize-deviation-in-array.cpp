class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        
        priority_queue<int>pq;
        int minEle = INT_MAX;
        
        //finding the minimum element minEle
       for(auto num : nums)
       {
           if(num%2==1)
           {
               num *= 2;
           }
           minEle = min(minEle,num);
           pq.push(num);
       }
        
        int minDev = INT_MAX;
        
        //reducing the maximum value here
        //last operation is remaining due to this condition
        while(pq.top()%2 == 0)
        {
            int maxi = pq.top();
            cout<<maxi<<endl;
            pq.pop();
            minDev = min(minDev,maxi-minEle);
             minEle = min(minEle , maxi/2);
            pq.push(maxi/2);
        }
        
        return min(minDev, pq.top()-minEle);
    }
};