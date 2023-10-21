class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int b=0;
        vector<int>temp;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1]==nums[i])
            {
                temp.push_back(nums[i]);
                b++;
            }
        }
        set<int>c(temp.begin(),temp.end());
        vector<int>t(c.begin(),c.end());
        if(b!=0)
        return t;
        else
        return{};
    }
};