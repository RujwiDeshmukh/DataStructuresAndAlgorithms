class Solution {
public:
    
    int cheapestPrice(vector<pair<int,int>> graph[],int n,int src,int dest,int k)
    {
        queue<pair<int,int>>q;
        //here we are creating pair as we can push single node multiple times
        //first arg will be node second will be distance
        q.push({0,src});
        //incrementing k as we have to consider that starting node as well
        k+=1;
        int ans=INT_MAX;
        vector<int>dis(n,INT_MAX);
        dis[src]=0;
        
        while(!q.empty())
        {
            //as we want to move level wise
            int size=q.size();
            k--;
            
            if(k<0)
            {
                break;
            }
            
            for(int i=0;i<size;i++)
            {
                auto pr = q.front();
                q.pop();
                
                int node = pr.second;
                int dist = pr.first;
                
                //traverse the adjacent nodes
                
                for(auto neigh : graph[node])
                {
                    if(neigh.second+dist < dis[neigh.first])
                    {
                        dis[neigh.first] = neigh.second+dist;
                        q.push({dis[neigh.first],neigh.first});
                    }
                }
                
            }
        }
        
        return dis[dest]==INT_MAX ? -1 : dis[dest];
        
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        //here we can't apply simple bfs as we cannot maintain visited array
        //due to visited array we will be able to visited one node at once only
        //bt as we have to find the minimum distance we can single node multiple 
        //times as we want the answer in k steps so here no need to use priority queue
        
        vector<pair<int,int>>graph[n];
        
        for(int i=0;i<flights.size();i++)
        {
            int fromCity = flights[i][0];
            int toCity = flights[i][1];
            int distance = flights[i][2];
            
            graph[fromCity].push_back({toCity,distance});
        }
        
        return cheapestPrice(graph,n,src,dst,k);
    }
};