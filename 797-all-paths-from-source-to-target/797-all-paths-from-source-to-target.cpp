class Solution {
public:
    
    void sourceToTarget(vector<vector<int>>& graph,int currentNode,int n,vector<int>& visited,
                       vector<int>& temp, vector<vector<int>>& ans)
    {
        if(currentNode==n-1)
        {
            ans.push_back(temp);
            return ;
        }
        
        if(visited[currentNode]==1)
        {
            return ;
        }
        //add node
        visited[currentNode]=1;
        
        for(int neighbour : graph[currentNode])
        {
            temp.push_back(neighbour);
            sourceToTarget(graph,neighbour,n,visited,temp,ans);
            temp.pop_back();
        }
        
        //here also backtrack
        visited[currentNode]=0;
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        vector<int>temp;
        int n = graph.size();
        vector<int>visited(n,0);
        
        //here we are passing the source here only to handle things 
        //more clearly
        temp.push_back(0);
        sourceToTarget(graph,0,n,visited,temp,ans);
        return ans;
    }
};