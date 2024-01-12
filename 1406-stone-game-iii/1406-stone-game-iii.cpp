class Solution {
public:
    int solve(vector<int>& sv , int i , vector<int>&dp)
    {
        if(i==sv.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans=INT_MIN;
        int total=0;
        for(int x=1 ;x<=3;x++)
        {
            if(x+i-1>=sv.size()) break;
            total+=sv[i+x-1];
            ans=max(ans, total-solve(sv,i+x , dp));
        }
        return dp[i]=ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        vector<int>dp(stoneValue.size()+1,-1);
        int ans= solve(stoneValue , 0 , dp);
        if(ans>0) return "Alice";
        if(ans<0) return "Bob";
        return "Tie";
    }
};