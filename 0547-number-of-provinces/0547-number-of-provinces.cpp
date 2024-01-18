class Solution {
public:
    void dfs(int src , vector<vector<int>>& isConnected ,  unordered_map<int , bool>&visited)
    {
        visited[src]=1;
        int size=isConnected[src].size();
        for(int col=0;col<size;col++)
        {
            if(isConnected[src][col]==1&& src!=col)
            {
                if(!visited[col])
                {
                    dfs(col , isConnected , visited);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int , bool>visited;
        int count=0;
        for(int i=0;i<isConnected.size();i++)
        {
            if(!visited[i])
            {
            dfs(i, isConnected , visited);
            count++;
            }
        }
        return count;
    }
};