class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        
        unordered_map<int,vector<int>> mp;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                mp[i-j].push_back(mat[i][j]);
            }
        }
        
        for(int k=-(m-1);k<n;k++)
        {
            sort(mp[k].begin(),mp[k].end());
        }
        
        for(int i=n-1;i>=0;i--) {
        for(int j=m-1;j>=0;j--) {
            mat[i][j]=mp[i-j].back();
            mp[i-j].pop_back();
        }
    }
     
        //can't use in case of vectors
      /*  for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                mat[i][j] = mp[i-j].top();
                mp[i-j].pop();
            }
        }*/
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<mat[i][j]<<" ";
            }
            
            cout<<endl;
        }
        
        
        return mat;
    }
};