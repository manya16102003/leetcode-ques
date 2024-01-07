class Solution {
public:
    int solve(vector<int>& nums, int target , int i , map<pair<int,int>,int>&dp)
    {
        if(i==nums.size()) return target==0?1:0;
        if(dp.find({i,target})!=dp.end()) return dp[{i,target}];
        int plus=solve(nums,target-nums[i],i+1,dp);
         int minus=solve(nums,target+nums[i],i+1,dp);
        return dp[{i,target}]= plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        map<pair<int,int>,int>dp;
        return solve(nums, target, 0 , dp);
    }
};