class Solution {
public:
    int findTheWinner(int n, int k) {
        //josephus problem
        //simulation problem with time complexicty of O(n2)
        //APPROACH 1
        // vector<int>ans;
        // for(int i=1;i<=n;i++)
        // {
        //     ans.push_back(i);
        // }
        // int i=0;
        // while(ans.size()!=1)
        // {
        //     int new_idx=(i+k-1)%ans.size();
        //     ans.erase(ans.begin()+new_idx);
        //     i=new_idx;
        // }
        // return ans[0];

        //APPROACH 2 USING QUEUE
        queue<int>queue;
        for(int i=1 ; i<=n ;i++)
        {
            queue.push(i);
        }

        while(queue.size()>1)
        {
            for(int count=1;count<=k-1 ;count++)
            {
                queue.push(queue.front());
                queue.pop();
            }
            queue.pop();
        }
        return queue.front();
    }
};