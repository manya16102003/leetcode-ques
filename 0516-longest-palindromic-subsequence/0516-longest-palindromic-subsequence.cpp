class Solution {
public:
    int solvetop_bottom(string &a, string &b)
    {
       vector<vector<int>>dp(a.length()+1,vector<int>(b.length()+1,0));
        // if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        for(int i=a.length()-1;i>=0;i--)
        {
            for(int j=b.length()-1;j>=0;j--)
            {
                if(a[i]==b[j]) ans=1+dp[i+1][j+1];
                 else
            
                 {ans=0+max(dp[i+1][j],dp[i][j+1]);}
            dp[i][j]=ans;
            
        }
        }
        
        return dp[0][0];
    }
    int longestPalindromeSubseq(string s) {
        string first=s;
        reverse(s.begin(),s.end());
        string second =s;
        
        return solvetop_bottom(first,second);
    }
};