class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        
        vector<int>indegree(n+1,0);
        vector<int>outdegree(n+1,0);
        
        for(int i=0;i<trust.size();i++)
        {
            int src = trust[i][0];
            int dest = trust[i][1];
            
            indegree[dest]++;
            outdegree[src]++;
        }
        
        for(int i=1;i<=n;i++)
        {
            if((indegree[i]-outdegree[i])==(n-1))
            {
                return i;
            }
        }
        
        return -1;
    }
};