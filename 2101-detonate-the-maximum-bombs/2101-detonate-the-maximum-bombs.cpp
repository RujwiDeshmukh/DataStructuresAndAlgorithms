class Solution {
public:
  
    bool check(long long x1,long long  x2, long long  y1,long long  y2,long long  r)
    {
        long long x=(x1-x2)*(x1-x2), y=(y1-y2)*(y1-y2); 
        return x+y<=r*r; //using the distance formula
    }
    
    void help(vector<vector<int>>& bombs,vector<bool>& vis,int j, int& count){
        if(vis[j])return; //if we have already detonated this bomb 
        
        count++;
        vis[j]=true;
        int x1=bombs[j][0], y1=bombs[j][1], r=bombs[j][2];
        
        for(int i=0;i<bombs.size();i++){
            int x2=bombs[i][0], y2=bombs[i][1];
            if(!vis[i] && check(x1,x2,y1,y2,r)) //check if this bomb can be detonated using the previous bomb
            help(bombs,vis,i,count);
        }
    }
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        int ans=INT_MIN;
        
        for(int i=0;i<n;i++){
            int count=0; 
            vector<bool>visited(n,false);  // a visted array to keep track of the bombs already reached in the current sequence
            help(bombs,visited,i,count);
            ans=max(ans,count);
        }
        return ans;
    }
};