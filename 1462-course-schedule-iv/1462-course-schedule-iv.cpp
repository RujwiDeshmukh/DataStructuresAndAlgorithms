class Solution {
public:
    vector<bool> checkIfPrerequisite(int n,vector<vector<int>>& vt, vector<vector<int>>& qr) {
        
        //first thing will be we will construct the graph
        vector<int>adj[n];
         vector<int>indegree(n,0);
        vector<vector<bool>>preRelation(n, vector<bool>(n, false));
        
        for(int i=0;i<vt.size();i++)
        {
            vector<int>temp = vt[i];
            
            adj[temp[0]].push_back(temp[1]);
            indegree[temp[1]]++;
            preRelation[temp[0]][temp[1]] =true;
        }
        
        queue<int>q;
        
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            for(auto &neigh : adj[node])
            {
                //we will check for that particular edge relation exist
                //if it is prerequisite then for its neighbour node it will also be prerequisite
                for(int i=0;i<n;i++)
                {
                     if(preRelation[i][node]==true)
                     {
                         preRelation[i][neigh] = true; 
                     }
                }
                if(indegree[neigh] > 0)
                {
                    indegree[neigh]--;
                }
                
                if(indegree[neigh] == 0)
                {
                    q.push(neigh);
                }
            }
            
        }
        
        vector<bool>res;
        
        for(int i=0;i<qr.size();i++)
        {
            res.push_back(preRelation[qr[i][0]][qr[i][1]]);
        }
        return res;
    }
};