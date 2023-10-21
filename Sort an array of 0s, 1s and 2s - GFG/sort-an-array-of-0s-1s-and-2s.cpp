//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int nums[], int n)
    {
        // code here
          int s=0, m=0;
        int e=n-1;
        while(m<=e)
        {
            if(nums[m]==0)
            {
                swap(nums[s],nums[m]);
                m++;
                s++;
            }
           else if(nums[m]==1)
            {
                m++;
            }
            else if(nums[m]==2)
            {
                swap(nums[m],nums[e]);
                e--;
            }
        }
        
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends