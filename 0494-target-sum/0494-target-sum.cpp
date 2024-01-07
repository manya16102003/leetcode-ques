class Solution {
public:
    int solve(vector<int>& nums, int target , int i)
    {
        if(i==nums.size()) return target==0?1:0;
        int plus=solve(nums,target-nums[i],i+1);
         int minus=solve(nums,target+nums[i],i+1);
        return plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums, target, 0);
    }
};