class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        
        
         int x[8] = {0,0,1,1,1,-1,-1,-1};
        int y[8]= {1,-1,1,0,-1,1,-1,0};
        
        int n = board.size();
        int m = board[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int live=0;
                //for all the 8 directions
                for(int k=0;k<8;k++)
                {
                    int row = x[k]+i;
                    int col = y[k]+j;
      
                    //as we are not updating cells simultaneously we have marked live cells as -1 so need to consider that situation for counting live cells
     if(row>=0 && row<n && col>=0 && col<m && (board[row][col]==1 || board[row][col]==-1))
                    {
                        live++;
                    }
                }
                    
                     if(board[i][j]==1 && ((live<2) || (live>3)))
                     {
                         //if condition is true then mark it as dead situation
                         board[i][j]=-1;
                     }
                     else if(board[i][j]==1 && ((live==2) || (live==3)))
                     {
                         board[i][j]=1;
                     }
                    else if(board[i][j]==0 && (live==3))
                    {
                        board[i][j]=2;
                    }
                }
            }
    
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(board[i][j]==-1)
            {
               board[i][j]=0; 
            }
            else if(board[i][j]==2)
            {
                board[i][j]=1;
            }
        }
    }
    }
};