class Solution {
public:
    int solve(int n)
    { 
        
        vector<vector<int>>dp(n+1,vector<int>(n+2,0));
        for(int start=n;start>=1;start--)
        {
            for(int end=1;end<=n;end++)
            {
                if(start>=end) continue;
                else
                {
                    int count=INT_MAX;
                    for(int i=start;i<end;i++)
                    {
                        count=min(count,i+max(dp[start][i-1],dp[i+1][end]));
                    }
                   dp[start][end]= count; 
                }
               
                
            }
        }
       
       return dp[1][n]; 
        
    }
    int getMoneyAmount(int n) {
        
        int ans=solve(n);
        return ans;
    }
};