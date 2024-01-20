class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int> , int>>q;
        vector<vector<int>>ans=grid;
        int anstime=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2)
                q.push({{i , j},0});
            }
        }
        int dx[]={1, 0,0, -1};
        int dy[]={0 , 1 , -1, 0};
        while(!q.empty())
        {
            auto frontnode=q.front();
            q.pop();
            int r=frontnode.first.first;
            int c=frontnode.first.second;
            int time=frontnode.second;
            for(int i=0;i<4 ; i++)
            {
                int newdx=dx[i]+r;
                int newdy=dy[i]+c;
                if(newdx>=0&& newdx<grid.size() && newdy>=0 && newdy<grid[0].size()
                && ans[newdx][newdy]==1)
                {
                    anstime=max(time+1 , anstime);
                    q.push({{newdx , newdy}, time+1});
                    ans[newdx][newdy]=2;
                }
            }
            
        }
        for(int i=0; i<ans.size();i++)
        {
            for(int j=0;j<ans[0].size();j++)
            {
                if(ans[i][j]==1) return -1;
            }
        }
        return anstime;
    }
};