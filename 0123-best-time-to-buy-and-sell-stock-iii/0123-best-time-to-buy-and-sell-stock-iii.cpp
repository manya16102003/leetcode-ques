class Solution {
public:
    int solvetb(vector<int>& prices,int buy,int i, int limit,vector<vector<vector<int>>>&dp)
    {
        if(i>=prices.size()||limit==0) return 0;
        if(dp[i][buy][limit]!=-1) return dp[i][buy][limit];
        int profit=0;
        if(buy)
        {
            int stockprofit=-prices[i]+solvetb(prices,0,i+1,limit,dp);
            int ignore=solvetb(prices,1,i+1,limit,dp);
            profit=max(stockprofit,ignore);
        }
        else
        {
             int sellprofit=prices[i]+solvetb(prices,1,i+1,limit-1,dp);
            int ignore=solvetb(prices,0,i+1,limit,dp);
            profit=max(sellprofit,ignore);
        }
        dp[i][buy][limit]=profit;
        return profit;
    }
    int maxProfit(vector<int>& prices) {
       vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(2,vector<int>(3,-1))) ;
        return solvetb(prices,1,0,2,dp);
    }
};