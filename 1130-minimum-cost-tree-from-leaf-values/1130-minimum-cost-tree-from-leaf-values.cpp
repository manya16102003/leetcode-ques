class Solution {
public:
    int solve(vector<int>& arr,map<pair<int,int>,int>&maxi,int left,int right, int n)
{
    
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
   
       
        for(int left=n-1;left>=0;left--)
        {
            for(int right=0;right<=n-1;right++)
            {
                if(left>=right) continue;
                else
                {
                     int ans=INT_MAX;
                
                 for(int i =left;i<right;i++)
                    {
                    ans=min(ans,maxi[{left,i}]*maxi[{i+1,right}]+dp[left][i]+dp[i+1][right]);
                    }
                dp[left][right]=ans;
            }}
        }
   
    return dp[0][n-1];
}
    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int,int>,int>maxi;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            maxi[{i,i}]=arr[i];
            for(int j=i+1;j<n;j++)
            {
                maxi[{i,j}]=max(arr[j],maxi[{i,j-1}]);
            }
        }
       
        int ans=solve(arr,maxi,0,n-1,n);
        return ans;
    }
};