class Solution {
public:
      vector<int> toposort(unordered_map<int,list<int>>&adjlist , int numCourses)
    {
        queue<int>q;
        vector<int>ans;
        unordered_map<int,int>indegree;
        for(auto i:adjlist)
        {
        int src=i.first;
        for(auto nbr :i.second)
        {
            indegree[nbr]++;
        }
            
        }
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty())
        {
            int frontnode=q.front();
            q.pop();
            ans.push_back(frontnode);
            for(auto nbr:adjlist[frontnode])
            {
                indegree[nbr]--;
                if(indegree[nbr]==0)
                    q.push(nbr);
            }
        }
        if(ans.size()==numCourses) return ans;
        else return {};
      }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         unordered_map<int,list<int>>adjlist;
        for(auto c:prerequisites)
        {
            int u=c[0];
            int v =c[1];
            adjlist[v].push_back(u);
        }
        return toposort(adjlist, numCourses );
        
    }
};