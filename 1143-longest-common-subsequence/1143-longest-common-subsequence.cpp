class Solution {
public:
    // int solve(string &text1, string &text2, int i , int j,vector<vector<int>>&dp)
    // {
    //     if(i==text1.length()) return 0;
    //     if(j==text2.length()) return 0;
    //     int ans=0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(text1[i]==text2[j])
    //     {
    //         ans=1+solve(text1 , text2,i+1,j+1,dp);
    //     }
    //     else
    //     {
    //         ans=0+max(solve(text1,text2, i+1 ,j,dp),solve(text1,text2, i ,j+1,dp));
    //     }
    //     dp[i][j]=ans;
    //     return dp[i][j];
    // }
    int solvetab(string &text1, string &text2)
    {
       vector<vector<int>>dp(text1.length()+1,vector<int>(text2.length()+1,0));
        for(int i=text1.length()-1;i>=0;i--)
        {
            for(int j=text2.length()-1;j>=0;j--)
            {
                 int ans=0;
            
            if(text1[i]==text2[j])
            {
                ans=1+dp[i+1][j+1];
            }
            else
            {
                ans=0+max(dp[i+1] [j],dp[i][j+1]);
            }
                 dp[i][j]=ans;
            }
        }
        return dp[0][0];
        
    }
    int longestCommonSubsequence(string text1, string text2) {
        // int i=0;
        // int j=0;
        // vector<vector<int>>dp(text1.length(),vector<int>(text2.length(),-1));
        return solvetab(text1,text2);
        
    }
};