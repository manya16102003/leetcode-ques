//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int find_pivot(int A[], int l, int h)
    {
        int mid=(l+h)/2;
        while(l<=h)
        {
            if(l==h) return l;
            if(mid+1<=h&&A[mid]>A[mid+1]) return mid;
            if(mid-1>=l&&A[mid-1]>A[mid]) return mid-1;
            if(A[l]>=A[mid]) h=mid-1;
            else
            {
                l=mid+1;
            }
            mid=(l+h)/2;
        }
        return -1;
    }
    int bs(int A[], int l, int h, int key)
    {
        int mid=(l+h)/2;
        while(l<=h)
        {
            if(key==A[mid] ) return mid;
            else if(key<A[mid]) h=mid-1;
            else l=mid+1;
            mid=(l+h)/2;
            
        }
        return -1;
    }
    int search(int A[], int l, int h, int key){
        // l: The starting index
        // h: The ending index, you have to search the key in this range
        
        //complete the function here
        int ans=-1;
        int pivot=find_pivot(A, l,h);
        if(key>=A[l]&&key<=A[pivot])
        ans= bs(A,l,pivot,key);
        else
        ans= bs(A,pivot+1,h,key);
        return ans;
    }
};

//{ Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}
// } Driver Code Ends