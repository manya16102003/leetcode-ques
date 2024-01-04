class Solution {
public:
int solve(vector<int>& prices , int i, int buy, int k,vector<vector<vector<int>>>&dp)
{
    if(i>=prices.size()|| k==0) return 0;
    if(dp[i][buy][k]!=-1) return dp[i][buy][k];
    int profit=0;
    if(buy)
    {
        int profit_buy=-prices[i]+solve(prices,i+1,0,k,dp);
        int ignore_profit=solve(prices,i+1,1,k,dp);
        profit=max(profit_buy , ignore_profit);
    }
    else
    {
        int profit_sell=prices[i]+solve(prices,i+1,1,k-1,dp);
        int ignore_profit=solve(prices,i+1,0,k,dp);
        profit=max(profit_sell , ignore_profit);
    }
    dp[i][buy][k]=profit;
    return profit;
}
    int maxProfit(int k, vector<int>& prices) {
       vector<vector<vector<int>>>dp(prices.size(),      vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(prices,0,1,k,dp);
    }
};