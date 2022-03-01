class Solution {
public:
    
    void reorderPaths(int currCity,vector<int>adjCities[],vector<int>& vis,int & count)
    {
         vis[currCity]=1;
        
        //traverse adjacent cities
        
        for(auto city : adjCities[currCity])
        {
            if(!vis[abs(city)])
            {
               if(city>0)
               {
                   //increasing the count as we want to rverse this edge
                   count++;
               }
                
                reorderPaths(abs(city),adjCities,vis,count);
            }
        }
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        
        vector<int>adjCities[n];
        vector<int>vis(n,0);
        
        for(auto &connect : connections)
        {
            int cityFrom = connect[0];
            int cityTo = connect[1];
            
            adjCities[cityFrom].push_back(cityTo);
            adjCities[cityTo].push_back(-cityFrom);
        }
        
        //start the dfs from the city 0
        int count=0;
        reorderPaths(0,adjCities,vis,count);
        return count;
    }
};