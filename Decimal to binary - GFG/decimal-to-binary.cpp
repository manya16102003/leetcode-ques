//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

void toBinary(int N)
{
    // your code here
    vector<int>ans;
    while(N>0)
    {
        int bit=N%2;
        ans.push_back(bit);
        N=N/2;
    }
       reverse(ans.begin(),ans.end()); 
       for(auto i:ans)
       {
           cout<<i;
       }
}

//{ Driver Code Starts.

int main() {
	//code
	
	int t;
	cin>>t;
	
	
	while(t--)
	{
	    int n;
	    cin>>n;
	    
	    toBinary(n);
	    cout<<endl;
	}
	return 0;
}
// } Driver Code Ends