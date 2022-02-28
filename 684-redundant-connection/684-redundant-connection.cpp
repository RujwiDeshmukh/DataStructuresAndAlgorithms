class Solution {
public:
    
    int findParent(vector<int>& parent,int node)
    {
        if(parent[node]==node)
        {
            return node;
        }
        
        int temp = findParent(parent,parent[node]);
        parent[node]=temp;
        return temp;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();
        
        vector<int>parent(n+1);
        vector<int>rank(n+1);
        
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
            rank[i]=1;
        }
        
        for(vector<int> &e : edges)
        {
            int src = e[0];
            int dest = e[1];
            
            int parentSrc = findParent(parent,src);
            int parentDest = findParent(parent,dest);
            
            cout<<parentSrc<<endl;
            cout<<parentDest<<endl;
            
            if(parentSrc!=parentDest)
            {
                if(rank[parentSrc] > rank[parentDest])
                {
                    parent[parentDest] = parentSrc; 
                }
                else if(rank[parentSrc] < rank[parentDest])
                {
                   parent[parentSrc] = parentDest;    
                }
                else
                {
                    parent[parentSrc] = parentDest;
                    rank[parentDest]++;
                }
            }
            else
            {
                return e;
            }
        }
        return {};
    }
};