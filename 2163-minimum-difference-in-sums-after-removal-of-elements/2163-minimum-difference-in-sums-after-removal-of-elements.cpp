class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        #define ll long long
        int n=nums.size()/3;
        vector<ll>prefix(nums.size(),-1), surffix(nums.size(),-1);
        priority_queue<ll>pq;
        ll sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            pq.push(nums[i]);
            if(pq.size()>n)
            {
                sum-=pq.top();
                pq.pop();
            }
            if(pq.size()==n)
            {
                prefix[i]=sum;
            }
        }
        sum=0;
        priority_queue<ll,vector<ll>,greater<ll>>pq2;
          for(int i=nums.size()-1;i>0;i--)
        {
            sum+=nums[i];
            pq2.push(nums[i]);
            if(pq2.size()>n)
            {
                sum-=pq2.top();
                pq2.pop();
            }
            if(pq.size()==n)
            {
                surffix[i]=sum;
            }
        }
        ll ans=LONG_LONG_MAX;
        for(int i=n-1;i<2*n;i++)
        {
            ans=min(ans,prefix[i]-surffix[i+1]);
        }
        return ans;
    }
};