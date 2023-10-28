class Solution {
public:
int perfectsquare(int n, vector<int>&dp)
{
    if(n==0) return 1;
    if(n<0)return 0;
    if(dp[n]!=-1) return dp[n];
    int i=1;
    int ans=INT_MAX;
    int end=sqrt(n);
    while(i<=end)
    {
        int perfectsq=i*i;
        int numberofperfectsquare=1+perfectsquare( n-perfectsq,dp);
        if(numberofperfectsquare<ans) ans=numberofperfectsquare;
        ++i;

    }
    dp[n]=ans;
    return dp[n];
}
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        int ans=perfectsquare(n,dp);
        return ans-1;
    }
};