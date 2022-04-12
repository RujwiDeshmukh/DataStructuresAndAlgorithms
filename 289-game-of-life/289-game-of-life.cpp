class Solution {
public:
    int getLiveNeighbours(int row,int col,vector<vector<int>>& board)
    {
          int n = board.size();
          int m = board[0].size();
        
          int cnt=0;
         
          if(row-1 >= 0 && board[row-1][col]==1) cnt++;
          if(row+1 < n && board[row+1][col]==1) cnt++;
          if(col-1 >= 0 && board[row][col-1]==1) cnt++;
          if(col+1 < m && board[row][col+1]==1) cnt++;;
          if(row-1 >= 0 && col-1 >= 0 && board[row-1][col-1]==1) cnt++;
          if(row-1 >= 0 && col+1 < m && board[row-1][col+1]==1) cnt++;
          if(row+1 < n && col-1 >= 0 && board[row+1][col-1]==1) cnt++;
          if(row+1 < n && col+1 < m && board[row+1][col+1]==1) cnt++;
        
        cout<<cnt<<endl;
        return cnt;
    }
    
    
    void gameOfLife(vector<vector<int>>& board) {
        
        int r = board.size();
        int c = board[0].size();
        vector<vector<int>> tempBoard = board;
        //passing original copy every time as we are not allowed to
        //update the values in a matrix simultaneously
        //https://leetcode.com/problems/game-of-life/discuss/1225591/C%2B%2B-two-approaches-with-intuition-or-faster-than-100
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                int liveNeighbour = getLiveNeighbours(i,j,tempBoard);
                
                if(board[i][j]==1)
                {
                    if((liveNeighbour<2) || (liveNeighbour>3))
                    {
                        board[i][j]=0;
                    }
                }
                else
                {
                   if(liveNeighbour == 3)
                   {
                       board[i][j] = 1;
                   }
                }
            }
        }
    }
};