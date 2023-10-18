class Solution {
public:
    int solve(string &a , string &b )
    {
         vector<vector<int>>dp(a.length()+1,vector<int>(b.length()+1,0));
        // if(i==a.length()) return b.length()-j;
        // if(j==b.length()) return a.length()-i;
        // if(dp[i][j]!=-1) return dp[i][j];
        for(int i=0;i<=b.length();i++)
            dp[a.length()][i]=b.length()-i;
        for(int i=0;i<=a.length();i++)
            dp[i][b.length()]=a.length()-i;
        
        for(int i=a.length()-1;i>=0;i--)
        {
            for(int j=b.length()-1;j>=0;j--)
            {
            int ans=0;
            if(a[i]==b[j]) ans=dp[i+1][j+1];
            else
            {
                int insert=1+dp[i][j+1];
                int Delete=1+dp[i+1][j];
                int replace=1+dp[i+1][j+1];
                ans=min(insert,min(Delete,replace));
                
            }
                 dp[i][j]=ans;
            }
        }
      
        
        return dp[0][0];
    }
    int minDistance(string word1, string word2) {
        if(word1.length()==0) return word2.length();
        if(word2.length()==0) return word1.length();
       
        return solve(word1,word2);
    }
};