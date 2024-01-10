class Solution {
public:
int lcp(string &a , string &b , int i , int j , vector<vector<int>>&dp)
{
    if(i==a.size()||j==b.size()) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans=0;
    if(a[i]==b[j])
    ans=1+lcp(a , b , i+1 , j+1 , dp);
    else
    {
        ans=max(lcp(a , b , i+1 ,j , dp),lcp(a , b, i , j+1 , dp));
    }
    return dp[i][j]=ans;
}
int longestcommonpalindrome(string &s)
{
    string a=s;
    reverse(s.begin(),s.end());
    string b =s;
    vector<vector<int>>dp(a.size(),vector<int>(b.size(),-1));
    return lcp(a , b , 0 , 0,dp);
}
    int minInsertions(string s) {
        int lps_length=longestcommonpalindrome(s);
        int insertion_length=s.size()-lps_length;
        return insertion_length;
    }
};