//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
   bool ispossible(int a[],int N, int M,int sol)
    {
        int pagesum=0;
        int c=1;
        for(int i=0;i<N;i++)
        {
            if(a[i]>sol)
                return false;
            if(pagesum+a[i]>sol)
            {
                c++;
                pagesum=a[i];
                if(c>M) 
                return false;
            }
            else
            {
                pagesum=pagesum+a[i];
            }
        }
            return true;
        
    }
    int findPages(int a[], int N, int M) 
    {
        //code here
        if(M>N) return -1;
        int start=0;
        int end=accumulate(a,a+N,0);
        int mid=(start+end)>>1;
        int ans=-1;
        while(start<=end)
        {
            if(ispossible(a,N,M,mid))
            {
                ans=mid;
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
            mid=(start+end)>>1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends