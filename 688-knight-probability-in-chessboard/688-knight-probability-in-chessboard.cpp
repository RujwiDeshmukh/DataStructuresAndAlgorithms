class Solution {
public:
    
 //   https://leetcode.com/problems/knight-probability-in-chessboard/discuss/664033/Simple-C%2B%2B-recursive-solution-with-memoization-beats-97-submission-4-ms
    
    double probabilityKnight(int n,int k,int row,int col,vector<vector<vector<double>>>& memo)
    {
        if(row<0 || row>=n || col>=n || col<0)
        {
             return 0.0;   
        }
        
        //as it is not moving so , it is present on that cell only 
        //so the probability on that cell only
        if(k==0)
        {
            return 1.0;
        }
        
        if(memo[row][col][k] != -1)
        {
            return memo[row][col][k];
        }
        
        double ans = 0.0;
        
        ans += probabilityKnight(n,k-1,row+2,col+1,memo);
        ans += probabilityKnight(n,k-1,row+2,col-1,memo);
        ans += probabilityKnight(n,k-1,row+1,col+2,memo);
        ans += probabilityKnight(n,k-1,row+1,col-2,memo);
        ans += probabilityKnight(n,k-1,row-1,col+2,memo);
        ans += probabilityKnight(n,k-1,row-1,col-2,memo);
        ans += probabilityKnight(n,k-1,row-2,col+1,memo);
        ans += probabilityKnight(n,k-1,row-2,col-1,memo);
        
        double result = ans/8.0;
        memo[row][col][k] = result;
        return memo[row][col][k];
    }
    
    
    double knightProbability(int n, int k, int row, int column) {
 vector<vector<vector<double>>>memo(n+1, vector<vector<double>>(n+1 , vector<double>(k+1,-1)));
        return probabilityKnight(n,k,row,column,memo);
    } 
};