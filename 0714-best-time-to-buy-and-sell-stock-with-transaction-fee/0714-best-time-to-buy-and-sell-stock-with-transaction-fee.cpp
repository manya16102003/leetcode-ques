class Solution {
public:
int solve (vector<int>& prices , int i , int buy , int fee , vector<vector<int>>&dp)
{
    if(i>=prices.size()) return 0;
    if(dp[i][buy]!=-1) return dp[i][buy];
    int profit=0;
    if (buy)
    {
        int buy_profit=-prices[i]+solve(prices, i+1, 0 , fee , dp);
        int ignore_profit=solve(prices, i+1, 1, fee , dp);
        profit=max(buy_profit , ignore_profit);
    }
    else
    {
        int sell_profit=prices[i]+solve(prices, i+1, 1, fee , dp)-fee;
        int ignore_profit=solve(prices, i+1 , 0 , fee , dp);
        profit=max(sell_profit , ignore_profit);
    }
    dp[i][buy]=profit;
    return profit;
}
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return solve(prices , 0, 1 , fee , dp);
    }
};