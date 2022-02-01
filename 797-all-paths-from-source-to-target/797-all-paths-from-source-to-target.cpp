class Solution {
public:
    
    void sourceToTarget(vector<vector<int>>& graph,int currentNode,int n,vector<int>& visited,
                       vector<int>& temp, vector<vector<int>>& ans)
    {
        if(currentNode==n-1)
        {
            temp.push_back(currentNode);
            ans.push_back(temp);
            //backtracking
            temp.pop_back();
            return ;
        }
        
        if(visited[currentNode]==1)
        {
            return ;
        }
        //add node
        temp.push_back(currentNode);
        visited[currentNode]=1;
        
        for(int neighbour : graph[currentNode])
        {
            sourceToTarget(graph,neighbour,n,visited,temp,ans);
        }
        
        //here also backtrack
        visited[currentNode]=0;
        temp.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        vector<int>temp;
        int n = graph.size();
        vector<int>visited(n,0);
        
        sourceToTarget(graph,0,n,visited,temp,ans);
        return ans;
    }
};