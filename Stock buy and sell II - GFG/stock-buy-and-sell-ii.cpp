//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
  int solvetb(vector<int>& prices,int buy,vector<vector<int>>&dp,int i)
{
    if(i>=prices.size()) return 0;
    int profit=0;
    if(dp[i][buy]!=-1) return dp[i][buy];
    if(buy)
    {
        int stockprofit=-prices[i]+solvetb(prices,0,dp,i+1);
        int skip=solvetb(prices,1,dp,i+1);
        profit=max(stockprofit,skip); 
    }
    else
    {
       int sellprofit=prices[i]+solvetb(prices,1,dp,i+1);
        int skip=solvetb(prices,0,dp,i+1);
        profit=max(sellprofit,skip);  
    }
    dp[i][buy]=profit;
    return dp[i][buy];
}
    int stockBuyAndSell(int n, vector<int> &prices) {
        // code here
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return solvetb(prices,true,dp,0);
    
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> prices(n);
        Array::input(prices,n);
        
        Solution obj;
        int res = obj.stockBuyAndSell(n, prices);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends