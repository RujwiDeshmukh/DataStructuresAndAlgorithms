class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        //we have to visit those nodes only having indegree zero as they cannot be reached from
        //any other node
        //https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/discuss/805685/JavaC%2B%2BPython-Nodes-with-no-In-Degree
        
        vector<int>vis(n);
        vector<int>ans;
        
        for(auto & edge : edges)
        {
            int dest = edge[1];
            vis[dest]=1;
        }
        
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};