class Solution {
public:
    //bottom to up
    int solvebu(vector<int>& prices,int buy,int i, int limit,vector<vector<vector<int>>>&dp)
    {
       for(int i=prices.size()-1;i>=0;i--)
       {
           for(int buy=0;buy<2;buy++)
           {
               for(int limit=1;limit<3;limit++)
               {
                    int profit=0;
                    if(buy)
                    {
                        int stockprofit=-prices[i]+dp[i+1][0][limit];
                        int ignore=dp[i+1][1][limit];
                        profit=max(stockprofit,ignore);
                    }
                    else
                    {
                         int sellprofit=prices[i]+dp[i+1][1][limit-1];
                        int ignore=dp[i+1][0][limit];
                        profit=max(sellprofit,ignore);
                    }
                    dp[i][buy][limit]=profit;
                   
               }
           }
       }
       return dp[0][1][2]; 
    }
    //top to bottom
    
    //  int solvetb(vector<int>& prices,int buy,int i, int limit,vector<vector<vector<int>>>&dp)
    // {
    //     if(i>=prices.size()||limit==0) return 0;
    //     if(dp[i][buy][limit]!=-1) return dp[i][buy][limit];
    //     int profit=0;
    //     if(buy)
    //     {
    //         int stockprofit=-prices[i]+solvetb(prices,0,i+1,limit,dp);
    //         int ignore=solvtb(prices,1,i+1,limit,dp);
    //         profit=max(stockprofit,ignore);
    //     }
    //     else
    //     {
    //          int sellprofit=prices[i]+solvetb(prices,1,i+1,limit-1,dp);
    //         int ignore=solvetb(prices,0,i+1,limit,dp);
    //         profit=max(sellprofit,ignore);
    //     }
    //     dp[i][buy][limit]=profit;
    //     return profit;
    // }
    int maxProfit(vector<int>& prices) {
       // vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(2,vector<int>(3,-1))) ;
       //  return solvetb(prices,1,0,2,dp);
         vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(2,vector<int>(3,0))) ;
        return solvebu(prices,1,0,2,dp);
    }
};