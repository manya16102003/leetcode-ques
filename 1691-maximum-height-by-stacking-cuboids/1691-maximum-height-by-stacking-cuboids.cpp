class Solution {
public:
// bool check(vector<int>a,vector<int>b)
// {
//     if(b[0]<=a[0]&&b[1]<=a[1]&&b[2]<=a[2]) return true;
//     return false;
// }
int solve(vector<vector<int>>& cuboids,vector<vector<int>>&dp,int curr, int prev)
{
    if(curr>=cuboids.size()) return 0;
    if(dp[curr][prev+1]!=-1) return dp[curr][prev+1];
    int include=0;
    if(prev==-1||(cuboids[curr][0]>=cuboids[prev][0]&&cuboids[curr][1]>=cuboids[prev][1]&&cuboids[curr][2]>=cuboids[prev][2]))
    include=cuboids[curr][2]+solve(cuboids,dp,curr+1,curr);
    int exclude=0+solve(cuboids,dp,curr+1,prev);
    dp[curr][prev+1]=max(include,exclude);
    return dp[curr][prev+1];
}
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &a:cuboids)
        {
            sort(a.begin(),a.end());
        }
        sort(cuboids.begin(),cuboids.end());
        int curr=0;
        int prev=-1;
        int n=cuboids.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
         int ans=solve(cuboids,dp,curr,prev);
    return ans;
    }
};