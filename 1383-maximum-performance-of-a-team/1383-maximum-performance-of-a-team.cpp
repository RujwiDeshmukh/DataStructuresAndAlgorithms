class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        
        //https://leetcode.com/problems/maximum-performance-of-a-team/discuss/1252412/C%2B%2BJavaPython-MinHeap-Solution-Clean-and-Concise
        
       // https://leetcode.com/problems/maximum-performance-of-a-team/discuss/2560430/C%2B%2BIntuition-and-Explaination-oror-Priority-queue
        
        vector<pair<int,int>>engineers;
        int size = speed.size();
        
        for(int i=0;i<size;i++)
        {
            engineers.push_back({efficiency[i],speed[i]});
        }
        
        //we are sorting in decreasing order of efficiency
        //as we are always trying to have minimum efficiency
        //so we dont have to do extra work for efficiency to keep it minimum
        sort(engineers.rbegin(),engineers.rend());
        
        priority_queue<int,vector<int>,greater<int>>pq;
        long long totalSpeed=0;
        long long  ans=INT_MIN;
        
        for(auto eng : engineers)
        {
            int currEffi = eng.first;
            int currSpeed = eng.second;
            
            //now we have to maximize the speed 
            //removing the minimum speed from heap
            
            pq.push(currSpeed);
            
            if(pq.size() > k)
            {
                totalSpeed -= pq.top();
                pq.pop();
            }
            
            totalSpeed += currSpeed;
            ans = max(ans, totalSpeed*currEffi);
        }
        
         return ans % (int) (1e9 + 7);
    }
};