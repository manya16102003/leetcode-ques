//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
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
    int editDistance(string s, string t) {
        // Code here
         if(s.length()==0) return t.length();
        if(t.length()==0) return s.length();
        vector<vector<int>>dp(s.length(),vector<int>(t.length(),-1));
        return solve(s,t,0,0,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends