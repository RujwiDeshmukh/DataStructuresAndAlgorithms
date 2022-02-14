class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<vector<int>>adj(n);
        vector<int>indegree(n,0);
        queue<int>q;
        vector<int>ans;
        
        int i=0;
        
        for(auto &g : graph)
        {
            for(auto &it : g)
            {
                adj[it].push_back(i);
                indegree[i]++;
            }
            
            i++;
        }
        
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        
    //    https://leetcode.com/problems/find-eventual-safe-states/discuss/1548824/Multiple-Approaches-Explained-oror-BFS-and-DFS-oror-C%2B%2B-Clean-Code
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto it : adj[node])
            {
                indegree[it]--;
                
                if(indegree[it]==0)
                {
                    q.push(it);
                }
            }
        }
        
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};