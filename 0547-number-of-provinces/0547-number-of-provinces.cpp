class Solution {
public:
    
    void dfs(vector<int>adj[],vector<int>& visited,int i)
    {
          visited[i]=1;
        
        for(auto j : adj[i])
        {
            if(!visited[j])
            {
                dfs(adj,visited,j);
            }
        }
    }
    
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        vector<int>adj[n];
        vector<int>visited(n+1,0);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1 && i != j)
                {
                    adj[i].push_back(j);
                }
            }
        }
        
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                ans++;
               dfs(adj,visited,i); 
            }
        }
        
        return ans;
    }
};