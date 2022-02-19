class Solution {
public:
    
    int dfs(vector<vector<int>>& grid,int row,int col,int color)
    {
        int n = grid.size();
        int m = grid[0].size();
        
        if(row < 0 || col < 0 || row >= n || col >= m || grid[row][col] != 1)
        {
            return 0;
        }
        
        grid[row][col]=color;
        int area =1;
        
        area += dfs(grid,row-1,col,color);
        area += dfs(grid,row+1,col,color);
        area += dfs(grid,row,col+1,color);
        area += dfs(grid,row,col-1,color);
        
        return area;
    }
    
    int largestIsland(vector<vector<int>>& grid) {
    
        int n = grid.size();
        int m = grid[0].size();
        int count=0;
        int island_id=2;
        unordered_map<int,int>mp;
        int maxArea=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                   count =  dfs(grid,i,j,island_id);
                    mp[island_id] = count;
                    island_id++;
                    maxArea=max(count,maxArea);
                }
            }
        }
        
        //Until now we have only found the area in normal way
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                //now changing the parity
                if(grid[i][j]==0)
                {
                    //as we want to find the group of adjacent islands
                    //all unique islands having different island_id
                    //by traversing to all 4 sides of the cell
                    
                    set<int>st;
                    
                    if(i-1 >= 0 && grid[i-1][j] != 0)
                    {
                        st.insert(grid[i-1][j]);
                    }
                    
                     if(i+1 < n && grid[i+1][j] != 0)
                    {
                        st.insert(grid[i+1][j]);
                    }
                    
                     if(j-1 >= 0 && grid[i][j-1] != 0)
                    {
                        st.insert(grid[i][j-1]);
                    }
                    
                     if(j+1 < m && grid[i][j+1] != 0)
                    {
                        st.insert(grid[i][j+1]);
                    }
                    
                    int sum=1;
                    //sum is 1 as we are considering 0 as well
                    for(auto s : st)
                    {
                        //adding frequencies to sum
                        sum += mp[s];
                    }
                    
                    maxArea = max(maxArea,sum);
                }
            }
        }
        
        return maxArea==0?(m*n):maxArea; 
    }
};