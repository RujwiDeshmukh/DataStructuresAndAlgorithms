class Solution {
public:
    
    bool detectCycle(vector<vector<int>>& graph,int node,vector<int>& safe)
    {
        //mark it unSafe, when we first make the call
        
        safe[node]=1;
        
        for(auto neigh : graph[node])
        {
            //if it is already visited , then directly return true
            if(safe[neigh]==1)
            {
                return true;
            }
            //if it is not visited and after some times we came to know that 
            //from detectCycle we got true , then return true;
            else if(safe[neigh]==0 && detectCycle(graph,neigh,safe))
            {
                return true;
            }
        }
        
        //backtrack i.e. mark that node as safe
        safe[node]=2;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int>safe(n,0);
        vector<int>res;
        
        for(int i=0;i<n;i++)
        {
            //it worked same as visited work in bfs
            //if in previous cycle if the node is already marked as safe
            //then 2nd time we will directly add it ans
            //and wont make any calls
            if(safe[i]==2 || detectCycle(graph,i,safe)==false)
            {
                res.push_back(i);
            }
        }
        
        return res;
    }
};