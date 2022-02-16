class Solution {
public:
    
    int minTime(vector<pair<int,int>>graph[],int n,int src)
    {
        vector<int>dist(n+1,INT_MAX);
        int time=0;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,src});
        dist[src]=0;
        cout<<src<<endl;
        
        while(!pq.empty())
        {
            auto pr = pq.top();
            pq.pop();
            int node = pr.second;
            
            for(auto neigh : graph[node])
            {
                int nextNode = neigh.first;
                int nextDist = neigh.second;
                
                if(dist[nextNode] > dist[node]+nextDist)
                {
                    dist[nextNode] = dist[node]+nextDist;
                    pq.push({dist[nextNode],nextNode});
                }
            }
            
        }
        
        time = *max_element(dist.begin()+1,dist.end());
        
       return time==INT_MAX ? -1 : time;
        
    }
    
   // https://leetcode.com/problems/network-delay-time/discuss/1756203/Easy-C%2B%2B-Solution-or-Dijkstras-Algo-or-Explained
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<pair<int,int>>graph[n+1];
        
        for(int i=0;i<times.size();i++)
        {
            vector<int>temp = times[i];
            
            int src = temp[0];
            int dest = temp[1];
            int wt = temp[2];
            
            graph[src].push_back({dest,wt});
        }
    
        
      return  minTime(graph,n,k);
    }
};