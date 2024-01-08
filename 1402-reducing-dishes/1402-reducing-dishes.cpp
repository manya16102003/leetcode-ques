class Solution {
public:
    int solve(vector<int>& sat , int i , int time ,  vector<vector<int>>&dp)
    {
        if(i==sat.size()) return 0;
        if(dp[i][time]!=-1) return dp[i][time];
        int include=time*sat[i]+solve(sat,i+1, time+1 , dp);
        int exclude=solve(sat, i+1 , time , dp);
        return dp[i][time]=max(include, exclude);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        vector<vector<int>>dp(satisfaction.size(),vector<int>(satisfaction.size()+1,-1));
        return solve(satisfaction , 0 , 1 , dp);
    }
};