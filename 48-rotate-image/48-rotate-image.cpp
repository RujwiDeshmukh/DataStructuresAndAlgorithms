class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        
        for(int i=0;i<n;i++)
        {
            //as it is starting from 0
            //so for column of 4 , it will for iteration 0 1 only
            for(int j=0;j<m/2;j++)
            {
                swap(matrix[i][j],matrix[i][m-1-j]);
            }
        }
        
    }
};