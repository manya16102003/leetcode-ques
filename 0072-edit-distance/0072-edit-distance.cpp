class Solution {
public:
    int solve(string &a , string &b , int i , int j, vector<vector<int>>&dp )
    {
        if(i==a.length()) return b.length()-j;
        if(j==b.length()) return a.length()-i;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        if(a[i]==b[j]) ans=0+solve(a,b ,i+1,j+1,dp);
        else
        {
            int insert=1+solve(a,b,i,j+1,dp);
            int Delete=1+solve(a,b,i+1,j,dp);
            int replace=1+solve(a,b,i+1,j+1,dp);
            ans=min(insert,min(Delete,replace));
        }
        dp[i][j]=ans;
        return dp[i][j];
    }
    int minDistance(string word1, string word2) {
        if(word1.length()==0) return word2.length();
        if(word2.length()==0) return word1.length();
        vector<vector<int>>dp(word1.length(),vector<int>(word2.length(),-1));
        return solve(word1,word2,0,0,dp);
    }
};