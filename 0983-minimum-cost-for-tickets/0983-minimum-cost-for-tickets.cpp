class Solution {
public:
    int mincostTickets_helper(vector<int>& days, vector<int>& costs,int i,vector<int>&dp)
    {
        int ans=INT_MAX;
        if(i>=days.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        //1 day cost
        int cost1=costs[0]+mincostTickets_helper(days,costs,i+1,dp);
        //7 day cost
        int enddate=days[i]+7-1;
        int j=i;
        while(j<days.size()&&days[j]<=enddate)
        {
            j++;
        }
        int cost7=costs[1]+mincostTickets_helper(days,costs,j,dp);
        
         //30 day cost
        enddate=days[i]+30-1;
        j=i;
        while(j<days.size()&&days[j]<=enddate)
        {
            j++;
        }
        int cost30=costs[2]+mincostTickets_helper(days,costs,j,dp);
        dp[i]=min(cost1,min(cost7,cost30));
        return dp[i];
        
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(days.size(),-1);
        return mincostTickets_helper(days,costs,0,dp);
    }
};