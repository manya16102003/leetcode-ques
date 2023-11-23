class Solution {
public:
    void solve(vector<int>& prices,int &mini,int &maxi,int i)
    {
        if(i>=prices.size())
            return;
        if(prices[i]<mini)mini=prices[i];
        int total_profit=prices[i]-mini;
        if(total_profit>maxi)maxi=total_profit;
        solve(prices,mini,maxi,i+1);
    }
    int maxProfit(vector<int>& prices) {
        int mini=INT_MAX;
        int maxi=INT_MIN;
        solve(prices,mini,maxi,0);
        return maxi;
    }
};