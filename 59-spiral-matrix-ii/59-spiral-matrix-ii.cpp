class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>>matrix(n, vector<int>(n));
        
        int r1=0;
        int r2=n-1;
        int c1=0;
        int c2=n-1;
        int val=0;
        
        //equal condition will work for both even and odd rows and columns
        //equal work for odd
        //dry run to understand
        //https://leetcode.com/problems/spiral-matrix-ii/discuss/1941068/C%2B%2B-oror-0ms-oror-100-oror-Easy-To-Understand
        while(r1<=r2 && c1<=c2)
        {
            for(int i=c1;i<=c2;i++)
            {
                matrix[r1][i] = ++val;
            }
            
            for(int i=r1+1;i<=r2;i++)
            {
                matrix[i][c2] = ++val;
            }
            
            
            for(int i=c2-1;i>c1;i--)
            {
                matrix[r2][i] = ++val;
            }
            
            for(int i=r2;i>r1;i--)
            {
                matrix[i][c1] = ++val;
            }
            
            r1++;
            r2--;
            c1++;
            c2--;
        }
        
        return matrix;
    }
};