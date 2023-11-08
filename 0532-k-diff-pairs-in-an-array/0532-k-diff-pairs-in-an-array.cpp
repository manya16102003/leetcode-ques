class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        set<pair<int, int>>s;
        int i=0;
        int j=1;
        while(j<nums.size())
        {
            int diff=nums[j]-nums[i];
            if(diff==k)
            {
               s.insert({nums[i] , nums[i]});
                i++;
                j++;
            }
                
            else if(diff>k) i++;
            else j++;
            if(i==j) j++;
        }
        return s.size();
        
        
    }
};