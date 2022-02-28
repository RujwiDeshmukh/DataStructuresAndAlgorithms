class Solution {
public:
    
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
    
    bool equationsPossible(vector<string>& equations) {
        
        //https://leetcode.com/problems/satisfiability-of-equality-       equations/discuss/234486/JavaC%2B%2BPython-Easy-Union-Find
        
        vector<int>parent(27);
         
        for(int i=0;i<26;i++)
        {
            parent[i]=i;
        }
        
        for(auto eq : equations)
        {
            if(eq[1] == '=')
            {
                int x = findParent(eq[0]-'a',parent);
                int y = findParent(eq[3]-'a',parent);
                parent[x]=y;
            }
        }
        
         for(auto eq : equations)
        {
            if(eq[1] == '!')
            {
                int x = findParent(eq[0]-'a',parent);
                int y = findParent(eq[3]-'a',parent);
                
                if(x==y)
                {
                    return false;
                }
            }
        }
        return true;
    }
};