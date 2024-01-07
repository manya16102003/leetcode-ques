class Solution {
public:
    void coverttonumstr(vector<string>& strs , vector<pair<int,int>>&numstr )
    {
        for(auto str:strs)
        {
            int zeros=0 , ones=0;
            for(auto i:str)
            {
                if(i=='0')zeros++;
                else ones++;
            }
            numstr.push_back({zeros , ones});
        }
    }
    
    int solve (vector<pair<int,int>>&numstr , int m, int n,int i ,  vector<vector<vector<int>>>&dp)
    {
        if(i==numstr.size()) return 0;
        if(dp[i][m][n]!=-1)return dp[i][m][n];
        int zero= numstr[i].first;
        int one=numstr[i].second;
        int include=0 , exclude =0;
        if(m-zero>=0&& n-one>=0)
        {
            include=1+solve(numstr,m-zero,n-one,i+1,dp);
        }
        exclude=solve(numstr,m,n,i+1 , dp);
        return dp[i][m][n]=max(include,exclude);
        
        
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>>numstr;
        coverttonumstr(strs,numstr);
        vector<vector<vector<int>>>dp(numstr.size(),vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return solve(numstr,m , n,0 ,dp);
    }
};