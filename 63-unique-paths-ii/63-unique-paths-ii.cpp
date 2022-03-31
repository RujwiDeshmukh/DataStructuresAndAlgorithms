class Solution {
public:
    
    int dp[101][101];
  
    int countPaths(int r,int c,int row,int col,vector<vector<int>> &obstacleGrid)
    {       
                
       if( r == row-1 and c == col-1 &&  obstacleGrid[ r ][ c ] == 0) return 1;
        
       if(r >= row || c >= col)
       {
           return 0;
       }
        
        if(obstacleGrid[r][c]==1)  return 0;

        if(dp[ r ][ c ] != -1 ) return dp[ r ][ c ];
                    
        int left = 0 , right = 0; 
        
          left =   countPaths( r + 1 , c , row , col , obstacleGrid );
        
          right  =   countPaths( r , c + 1 , row , col , obstacleGrid );
                
        return dp[ r ][ c ] = left + right;
        
    }
    
    int uniquePathsWithObstacles( vector < vector < int > > & obstacleGrid) {
              
        memset( dp , -1 , sizeof( dp ));
        
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

       return countPaths( 0 , 0 , n , m , obstacleGrid );
       
    }
 
};