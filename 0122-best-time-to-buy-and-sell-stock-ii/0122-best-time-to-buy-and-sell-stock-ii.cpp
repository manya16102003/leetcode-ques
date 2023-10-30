class Solution {
public:
int solvetb(vector<int>& prices,int buy,vector<vector<int>>&dp,int i)
{
    if(i>=prices.size()) return 0;
    int profit=0;
    if(dp[i][buy]!=-1) return dp[i][buy];
    if(buy)
    {
        int stockprofit=-prices[i]+solvetb(prices,0,dp,i+1);
        int skip=solvetb(prices,1,dp,i+1);
        profit=max(stockprofit,skip); 
    }
    else
    {
       int sellprofit=prices[i]+solvetb(prices,1,dp,i+1);
        int skip=solvetb(prices,0,dp,i+1);
        profit=max(sellprofit,skip);  
    }
    dp[i][buy]=profit;
    return dp[i][buy];
}

int solvebu(vector<int>& prices,vector<vector<int>>&dp)
{
    for(int i=prices.size()-1;i>=0;--i)
    {
        for(int buy=0;buy<2;buy++)
        {
        int profit=0;
        if(buy)
        {
            int stockprofit=-prices[i]+dp[i+1][0];
            int skip=dp[i+1][1];
            profit=max(stockprofit,skip); 
        }
        else
        {
        int sellprofit=prices[i]+dp[i+1][1];
            int skip=dp[i+1][0];
            profit=max(sellprofit,skip);  
        }
        dp[i][buy]=profit;
        
        }
    }
    
   return dp[0][1];
   
}
    int maxProfit(vector<int>& prices) {
        // vector<vector<int>>dp(prices.size()+1,vector<int>(2,0));
      // return solvebu(prices,dp);
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return solvetb(prices,true,dp,0);
    }
};