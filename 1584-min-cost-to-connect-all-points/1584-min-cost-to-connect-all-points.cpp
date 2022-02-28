class Solution {
public:
    
    int findDistance(vector<int>& a, vector<int>& b)
    {
        return (abs(a[0]-b[0]) + abs(a[1]-b[1]));
    }
    
    void Unionn(int src,int dest,vector<int>& parent,vector<int>& rank)
    {
        
        src = findParent(src,parent);
        dest = findParent(dest,parent);
        if(src==dest)
        {
            return ;
        }
        
        if(rank[src] < rank[dest])
        {
            parent[src] = dest;
        }
        else if(rank[dest] < rank[src])
        {
            parent[dest] = src;
        }
        else
        {
            parent[dest] = src;
            rank[src]++;
        }
    }
    
    int findParent(int node,vector<int>& parent)
    {
        if(parent[node]==node)
        {
            return node;
        }
        
        int temp = findParent(parent[node],parent);
        parent[node]=temp;
        return parent[node];
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        //calculate the distance between any 2 given points 
        int n = points.size();
        vector<pair<int,pair<int,int>>>graph;
        vector<int>parent(n);
        
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
        
        vector<int>rank(n,1);
         int minCost = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int dist = findDistance(points[i],points[j]);
                graph.push_back(make_pair(dist,make_pair(i,j)));
                //it is stored in the format dist,src, dest as we want to sort on the basis
               //of dist
               //here vector<vector<int>>graph[n] wont work as it is the list of array
               //so we cannot sort it
            }
        }
        
        sort(graph.begin(),graph.end());
        
        //now apply krushkals algo here
        
        for(auto & edge : graph)
        {
            int dist = edge.first;
            int src = edge.second.first;
            int dest = edge.second.second;
            //cout<<dest<<endl;
            
            //now check if those 2 nodes have same parent or not
                
            if(findParent(src,parent) != findParent(dest,parent))
            {
                minCost += dist;
                cout<<minCost<<endl;
                Unionn(src,dest,parent,rank);
            }
        }
        
        return minCost;
    }
};