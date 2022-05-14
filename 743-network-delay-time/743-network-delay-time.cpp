class Solution {
public:
    
    int minTime(vector<pair<int,int>>graph[],vector<int>& dist,int src)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        dist[src]=0;
        int ans=0;
        
        pq.push({0,src});
        //distance and source
        while(!pq.empty())
        {
            auto pr = pq.top();
            pq.pop();
            int dis = pr.first;
            int node = pr.second;
            
            cout<<node<<endl;
            
            for(auto neigh : graph[node])
            {
                int nextDist = neigh.second;
                int nextDest = neigh.first;
                cout<<nextDist<<endl;
                
                if(dist[nextDest] > dist[node]+nextDist)
                {
                    dist[nextDest] = dist[node]+nextDist;
                    pq.push({dist[nextDest], nextDest});
                }
            }
        }
            
            ans = *max_element(dist.begin()+1,dist.end());
            
         return ans == INT_MAX ? -1 : ans;
    }
    
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<pair<int,int>>graph[n+1];
        vector<int>dist(n+1,INT_MAX);
        
        for(int i=0;i<times.size();i++)
        {
            vector<int>temp = times[i];
            int src = temp[0];
            int dest = temp[1];
            int dis = temp[2];
            
            graph[src].push_back({dest,dis});
        }
        
        return minTime(graph,dist,k);
        
    }
};