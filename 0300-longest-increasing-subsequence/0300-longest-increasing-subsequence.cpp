class Solution {
public:
    int solve(vector<int>& nums, int curr, int prev,vector<vector<int>>&dp )
    {
        if(curr>=nums.size()) return 0;
        if(dp[curr][prev+1]!=-1) return dp[curr][prev+1];
        int include=0;
        if(prev==-1||nums[prev]<nums[curr])
        include=1+solve(nums,curr+1,curr,dp);
        int exclude=0+solve(nums,curr+1,prev,dp);
        dp[curr][prev+1]=max(include,exclude);
        return dp[curr][prev+1];
    }
    
    int solvetab(vector<int>& nums)
    {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int curr=n-1;curr>=0;curr--)
        {
            for(int prev=curr-1;prev>=-1;prev--)
            {
                int include=0;
                if(prev==-1||nums[curr]>nums[prev])
                    include=1+dp[curr+1][curr+1];
                int exclude=0+dp[curr+1][prev+1];
                dp[curr][prev+1]=max(include,exclude);
            }
        }
        return dp[0][0];
        
    }
    int solvedpwithbinary(vector<int>& nums)
    {
        if(nums.size()==0) return 0;
        vector<int>ans;
        ans.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>ans.back()) ans.push_back(nums[i]);
            else
            {
                // override
                //find index of just bada element
                int index=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                ans[index]=nums[i];
            }
        }
        return ans.size();
    }
    int lengthOfLIS(vector<int>& nums) {
        int curr=0;
        int prev=-1;
        // int n=nums.size();
        // vector<vector<int>>dp(n,vector<int>(n+1,-1));
        // return solve(nums,curr,prev,dp);
        return solvedpwithbinary(nums);
    }
};