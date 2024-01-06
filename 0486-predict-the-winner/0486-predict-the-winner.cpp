class Solution {
public:
int solve (vector<int>& nums , int start , int end ,vector<vector<int>>&dp)
{
    if(start==end) return nums[start];
    if(dp[start][end]!=-1) return dp[start][end];
    int start_diff=nums[start]-solve(nums,start+1,end,dp);
    int end_diff=nums[end]-solve(nums,start,end-1,dp);
    dp[start][end]=max(start_diff , end_diff);
    return max(start_diff , end_diff);
}
    bool predictTheWinner(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),-1));
        return solve(nums , 0 , nums.size()-1 , dp)>=0;
    }
};