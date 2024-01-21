class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& height) {
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>dist(height.size(),vector<int>(height[0].size(),INT_MAX));
        pq.push({0,{0,0}});
        dist[0][0]=0;
        int dx[]={1, 0 , 0 , -1};
        int dy[]={0 , 1 , -1 , 0};
        while(!pq.empty())
        {
            auto frontnode=pq.top();
            pq.pop();
            int frontnodediff =frontnode.first;
            int x=frontnode.second.first;
            int y=frontnode.second.second;
            if(x==height.size()-1 &&y==height[0].size()-1) return dist[x][y];
            for(int i=0;i<4 ; i++)
                
            {
                int newx=dx[i]+x;
                int newy=dy[i]+y;
                if(newx>=0 && newx<height.size()&& newy>=0 && newy<height[0].size())
                {
                    int currdiff=abs(height[x][y]-height[newx][newy]);
                    int newMax= max(frontnodediff , currdiff);
                    if(newMax<dist[newx][newy])
                    {
                        dist[newx][newy]=newMax;
                        pq.push({newMax,{newx , newy}});
                    }
                }
             }
        }
        return 0;
    }
};