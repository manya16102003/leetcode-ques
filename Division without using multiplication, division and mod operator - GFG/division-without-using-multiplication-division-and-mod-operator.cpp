//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long divide(long long dividend, long long divisor) 
    {
        //code here
        if(dividend==INT_MIN && divisor==-1) return INT_MAX;
        int sign=1;
        if(dividend<0 || divisor<0)sign=-1;
        if(dividend<0 && divisor<0)sign=1;
        dividend=abs(dividend);
        divisor=abs(divisor);
        long long s=0;
        long long end=abs(dividend);
        long long mid=(s+end)/2;
        long long ans=0;
        while(s<=end)
        {
            if(abs(mid*divisor)==abs(dividend)) 
            {
                ans= mid;
                break;
            }
           if(abs(mid*divisor)>abs(dividend))
            {
                end=abs(mid-1);
            }
            else
            {
               ans=mid;
               s=abs(mid+1);
            }
            mid=(s+end)/2;
        }
         if(sign<0)return -ans;
        else return ans; 
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin >> t;

	while (t--)
	{

		long long a, b;
		cin >> a >> b;
		
		Solution ob;
		cout << ob.divide(a, b) << "\n";
	}

	return 0;
}

// } Driver Code Ends