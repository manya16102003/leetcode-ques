class Solution {
public:
vector<string>solve(string s ,unordered_map<string, bool>&dict , int i,unordered_map<int ,vector<string>>&dp)
{
    if(i==s.size()) return {""};
    if(dp.find(i)!=dp.end()) return dp[i];
    vector<string>ans;
    string word;
    for(int j=i ;j<s.size();j++)
    {
        word.push_back(s[j]);
        if(dict.find(word)==dict.end()) continue;
        //valid word found
        auto right=solve(s, dict, j+1,dp);
        for(auto rightpart:right)
        {
            string eachpart;
            if(rightpart.size()>0) eachpart=" "+rightpart;
            ans.push_back(word+eachpart);
        }
    }
    return dp[i]=ans;
}
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool>dict;
        for(auto i:wordDict) dict[i]=1;
        unordered_map<int ,vector<string>>dp;
        return solve(s, dict, 0,dp);
    }
};