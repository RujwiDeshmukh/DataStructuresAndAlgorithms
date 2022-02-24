class Solution {
public:
    
void tarjanDFS(vector<int>adj[],int node,int parent,vector<int>& disTime,vector<int>& minTime, vector<vector<int>>&ans, int &time)
    {
        disTime[node] = time;
        minTime[node] = time;
        
        time++;
    
        for(auto neigh : adj[node])
        {
            if(neigh==parent)
            {
                continue;
            }
            
            if(disTime[neigh] != -1)
            {
                minTime[node] = min(minTime[node],disTime[neigh]);
                continue;
            }
            //neighbour is not discovered yet
            
            tarjanDFS(adj,neigh,node,disTime,minTime,ans,time);
            
            minTime[node] = min(minTime[node],minTime[neigh]);
            
            if(disTime[node] < minTime[neigh])
            {
                vector<int>temp;
                temp.push_back(node);
                temp.push_back(neigh);
                ans.push_back(temp);
            }
        }
    
    }
    
    vector<vector<int>>Connections(int n , vector<int>adj[])
    {
        vector<int>disTime(n,-1);
        vector<int>minTime(n,-1);
        
        vector<vector<int>>ans;
        int time=0;
        
        tarjanDFS(adj,0,-1,disTime,minTime,ans,time);
        
        return ans;
        
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vector<int>adj[n];
        
        for(int i=0;i<connections.size();i++)
        {
            int src = connections[i][0];
            int dest = connections[i][1];
            
            adj[src].push_back(dest);
            adj[dest].push_back(src);
        }
        
        return Connections(n,adj);
    }
};