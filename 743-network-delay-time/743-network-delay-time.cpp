class Solution {
public:
    
    int minTime(vector<pair<int,int>> graph[], int src,vector<int>& dist)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,src});
        //src distance should be zero from itself
        dist[src]=0;
        int ans=0;
        
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
        
         ans = *max_element(dist.begin()+1,dist.end());
        
        return ans==INT_MAX ? -1 : ans;
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<pair<int,int>>graph[n+1];
        vector<int>dist(n+1,INT_MAX);
        for(int i=0;i<times.size();i++)
        {
            vector<int>temp = times[i];
            int src = temp[0];
            int dest = temp[1];
            int wt = temp[2];
            
            graph[src].push_back({dest,wt});
        }
        
       return minTime(graph,k,dist);
    }
};