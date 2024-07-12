class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // APPROACH 1 USING MAP
        // vector<int>ans;
        // int n=nums.size();
        // int occurrence=n/3;
        // unordered_map<int , int>mp;
        // for(int i=0;i<n;i++)
        // {
        //     mp[nums[i]]++;
        // }
        // for(auto i:mp)
        // {
        //     if(i.second>occurrence)
        //     {
        //         ans.push_back(i.first);
        //     }
        // }
        // return ans;

        //APPROACH 2 Moore's Voting Algorithm
        //WE KNOW THAT THER CAN BE ATMOST 2 ELEMENT HAVING FREQUENCY > N/3 TIMES
        int count1=0;
        int count2=0;
        int element1=INT_MIN;
        int element2=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            if(count1==0 && element2!=nums[i])
            {
                count1=1;
                element1=nums[i];
            }
            else if(count2==0 && element1!=nums[i])
            {
                count2=1;
                element2=nums[i];
            }
            else if(element1==nums[i]) count1++;
            else if(element2==nums[i]) count2++;
            else
            {
                count1--;
                count2--;
            }

        }
        vector<int>ans;
        count1=0 , count2=0;
        for(int i=0;i<nums.size();i++ )
        {
            if(nums[i]==element1) count1++;
            if(nums[i]==element2) count2++;
        }
        if(count1>nums.size()/3) ans.push_back(element1);
        if(count2>nums.size()/3) ans.push_back(element2);
        return ans;
    }
};