class Solution {
public:
int solve(int i , int j ,int m , int n , vector<vector<int>>&dp)
{
    if(i==m-1 && j==n-1) return 1;
    if(i>m || j>n) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans1=solve(i , j+1 , m , n , dp);
    int ans2=solve(i+1 , j , m ,n , dp);
    return dp[i][j]= ans1+ans2;
}
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1 ,vector<int>(n+1 , -1));
        int ans=solve(0 , 0 , m , n , dp);
        return ans;
    }
};