class Solution {
public:
    void solve(vector<int>& prices , int i , int &minprice , int &maxprofit)
    {
        if(i>=prices.size()) return ;
        if(minprice > prices[i]) minprice=prices[i];
        if(maxprofit<prices[i]-minprice) maxprofit=prices[i]-minprice;
        solve(prices , i+1 , minprice , maxprofit);

    }
    int maxProfit(vector<int>& prices) {
        int minprice=INT_MAX;
        int maxprofit=INT_MIN;
         solve(prices , 0 , minprice , maxprofit);
         return maxprofit;
        
    }
};