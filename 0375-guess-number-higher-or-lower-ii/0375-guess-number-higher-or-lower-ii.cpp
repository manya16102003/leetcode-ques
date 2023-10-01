class Solution {
public:
    int solve(int start,int end,vector<vector<int>>&dp)
    {
        if(start>=end) return 0;
        if(dp[start][end]!=-1) return dp[start][end];
        int count=INT_MAX;
        for(int i=start;i<end;i++)
        {
            count=min(count,i+max(solve(start,i-1,dp),solve(i+1,end,dp)));
        }
        return dp[start][end]= count;
        
    }
    int getMoneyAmount(int n) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int ans=solve(1,n,dp);
        return ans;
    }
};