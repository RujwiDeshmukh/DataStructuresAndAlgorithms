class Solution {
public:
    string pushDominoes(string dominoes) {
        
        int n = dominoes.size();
        vector<int>forces(n,0);
        int force=0;
        
        for(int i=0;i<n;i++)
        {
            if(dominoes[i]=='L')
            {
                force=0;
            }
            else if(dominoes[i]=='R')
            {
                force=n;
            }
            else
            {
                force=max(0,force-1);
            }
            
            forces[i]+=force;
        }
        
        for(int i=n-1;i>=0;i--)
        {
            if(dominoes[i]=='R')
            {
                force=0;
            }
            else if(dominoes[i]=='L')
            {
                force=n;
            }
            else
            {
                force = max(0,force-1);
            }
            
            forces[i]-=force;
        }
        
        string ans = "";
        
        for(int i=0;i<n;i++)
        {
            if(forces[i]<0)
            {
                ans += 'L';
            }
            else if(forces[i]>0)
            {
                ans += 'R';
            }
            else
            {
                ans += '.';
            }
        }
        
        return ans;
    }
};