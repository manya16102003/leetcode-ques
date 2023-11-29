class Solution {
public:
    int ismatching(string &s,string &p,int si, int pi , vector<vector<int>>&dp)
    {
        if(si<0&&pi<0) return true;
        if(si>=0&&pi<0) return false;
        if(si<0&&pi>=0)
        {
            for(int i=0;i<=pi;i++)
            {
                if(p[i]!='*') return false;
            }
            return true;
        }
        if(dp[si][pi] !=-1) return dp[si][pi];
        if(s[si]==p[pi]||'?'==p[pi]) return dp[si][pi]= ismatching(s,p,si-1,pi-1,dp);
        else if(p[pi]=='*')
        {
            return dp[si][pi]=(ismatching(s,p,si,pi-1,dp)||ismatching(s,p,si-1,pi,dp));
        }
        else return false;
    }


    bool isMatch(string s, string p) {
        int si=s.size();
        int pi=p.size();
        vector<vector<int>>dp(si,vector<int>(pi,-1));
        return ismatching(s,p,si-1,pi-1,dp);
    }
};