class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
 vector<int>dp(n,-1);
 int alic=f(0,n,stoneValue,dp);
 if(alic>0)
     return "Alice";
 else if(alic<0)
     return "Bob";
 else
     return "Tie";
}

int f(int i,int n,vector<int>& value,vector<int> &dp){
 if(i>=n)
     return 0;
 if(dp[i]!=-1)
     return dp[i];
 int ans=INT_MIN;
 ans=max(ans,value[i]-f(i+1,n,value,dp));
 if(i+1<n)
     ans=max(ans,value[i]+value[i+1]-f(i+2,n,value,dp));
 if(i+2<n)
     ans=max(ans,value[i]+value[i+1]+value[i+2]-f(i+3,n,value,dp));
 
 return dp[i]=ans;

    }
};