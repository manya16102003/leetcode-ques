class Solution {
public:
    int longestIncreasingSubsequence(vector<int>& nums,vector<int>& lis)
    {
        if(nums.size()==0) return 0;
        vector<int>ans;
        ans.push_back(nums[0]);
        lis.push_back(1);
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>ans.back()) 
            {
                ans.push_back(nums[i]);
                lis.push_back(ans.size());
            }
            else
            {
                int index=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                ans[index]=nums[i];
                lis.push_back(index+1);
            }
        }
        return ans.size();  
    }  
    int minimumMountainRemovals(vector<int>& nums) {
        vector<int>lis , lds;
        longestIncreasingSubsequence(nums,lis);
        reverse(nums.begin(),nums.end());
        longestIncreasingSubsequence(nums, lds);
        int largestMountainSize=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            if(lis[i]==1||lds[nums.size()-i-1]==1)continue;
            largestMountainSize=max(largestMountainSize,lis[i]+lds[nums.size()-i-1]-1);
        }
        int minremoval=nums.size()-largestMountainSize;
        return minremoval;  
    }
};