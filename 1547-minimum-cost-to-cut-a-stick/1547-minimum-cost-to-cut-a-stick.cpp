class Solution {
public:

    int f(int start,int end, vector<int>& cuts,vector<vector<int>>& dp)
    {
             if(start > end)
             {
                 return 0;
             }

             if(dp[start][end] != -1)
             {
                 return dp[start][end];
             }

             int mini = 1e9;

             for(int ind=start;ind<=end;ind++)
             {
                 int cost = cuts[end+1]-cuts[start-1]+
                             f(start,ind-1,cuts,dp)+f(ind+1,end,cuts,dp);
                             mini = min(mini,cost);
             }

             return dp[start][end] = mini;
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int m = cuts.size();
        vector<vector<int>>dp(m+1, vector<int>(m+1,0));

        for(int i=m-1;i>=1;i--)
        {
            for(int j=i;j<=m-2;j++)
            {
                int mini=1e9;

                for(int ind=i;ind<=j;ind++)
                {
                    int cost = cuts[j+1]-cuts[i-1] + dp[i][ind-1]+ dp[ind+1][j];
                    //as cuts are j+1 so if we go upto last index then j+1 doesnt 
                    //exist in costs array
                    mini = min(mini,cost);
                }

                dp[i][j] = mini;
            }
        }

        return dp[1][m-2];
    }
};