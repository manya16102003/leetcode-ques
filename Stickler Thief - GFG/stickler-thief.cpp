//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
int solve( vector<int>&dp,int nums[],int n)
{
    if(n<0) return 0;
    if(n==0) return nums[0];
    if(dp[n]!=-1) return dp[n];
    int include=solve(dp,nums,n-2)+nums[n];
    int exclude=solve(dp,nums,n-1);
    dp[n]=max(include,exclude)+0;
    return dp[n];
}
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
       vector<int>dp(n+1,-1);
        return solve(dp,arr,n-1);
        
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends