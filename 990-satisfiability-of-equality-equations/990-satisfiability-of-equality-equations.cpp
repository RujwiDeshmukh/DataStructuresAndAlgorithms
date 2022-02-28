class Solution {
public:
    
    bool hasPath(vector<vector<int>>& equal,int src,int dest,vector<int>& vis)
    {
        if(src==dest)
        {
            return true;
        }
        
        vis[src]=1;
        
        for(auto it : equal[src])
        {
            if(vis[it]==0)
            {
                if(hasPath(equal,it,dest,vis))
                {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    bool equationsPossible(vector<string>& equations) {
        
        vector<vector<int>>equal(26);
        //only 26 lower case characters are present we are taking size as 26
        
        //created the graph between i.e. edge created between the edges having sign =
        for(auto & eq : equations)
        {
            if(eq[1] == '=')
            {
                equal[eq[0]-'a'].push_back(eq[3]-'a');
                equal[eq[3]-'a'].push_back(eq[0]-'a');
            }
        }
        
        //if we found the path betwwen the edge having sign ! , then it contradicts the situation
        
        for(auto & eq : equations)
        {
            if(eq[1]== '!')
            {
                vector<int>vis(26,0);
                if(hasPath(equal,eq[0]-'a',eq[3]-'a',vis))
                {
                    return false;
                }
            }
        }
        
        return true;
    }
};