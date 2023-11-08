//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int TotalPairs(vector<int>nums, int k){
	    // Code here
	    sort(nums.begin(),nums.end());
        set<pair<int, int>>s;
        int i=0;
        int j=1;
        while(j<nums.size())
        {
            int diff=nums[j]-nums[i];
            if(diff==k)
            {
               s.insert({nums[i] , nums[i]});
                i++;
                j++;
            }
                
            else if(diff>k) i++;
            else j++;
            if(i==j) j++;
        }
        return s.size();
        
	    
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
		cin >> n >> k;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.TotalPairs(nums, k);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends