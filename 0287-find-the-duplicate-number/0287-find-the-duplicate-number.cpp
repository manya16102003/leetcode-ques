class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       unordered_map<int,int>hash;
        int num=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            hash[nums[i]]++;
        }
        for(int i=0;i<n;i++)
        {
            if(hash[nums[i]]>1)
                num= nums[i];
        }
        return num;
    }
};