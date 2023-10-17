class Solution {
public:
    int solvetop_bottom(string &a, string &b, int i,int j,vector<vector<int>>&dp)
    {
        if(i==a.length()) return 0;
        if(j==b.length()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        if(a[i]==b[j]) ans=1+solvetop_bottom(a,b,i+1,j+1,dp);
        else
        {
            ans=0+max(solvetop_bottom(a,b,i+1,j,dp),solvetop_bottom(a,b,i,j+1,dp));
        }
        dp[i][j]=ans;
        return dp[i][j];
    }
    int longestPalindromeSubseq(string s) {
        string first=s;
        reverse(s.begin(),s.end());
        string second =s;
        vector<vector<int>>dp(first.length(),vector<int>(second.length(),-1));
        return solvetop_bottom(first,second,0,0,dp);
    }
};