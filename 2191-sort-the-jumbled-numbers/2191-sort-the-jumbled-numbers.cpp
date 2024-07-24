class Solution {
public:

    int findmappednum(int num , vector<int>& mapping )
    {
        if(num <10) return mapping[num];
        int mappednum=0;
        int placevalue=1;
        while(num)
        {
            int lastdigit=num%10;
            int mappeddigit=mapping[lastdigit];
            mappednum+=(mappeddigit*placevalue);
            placevalue*=10;
            num/=10;
        }
        return mappednum ;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
     int n=nums.size();
     vector<pair<int,int>>vec;
     for(int i=0;i<n;i++)
     {
        int mappednum=findmappednum(nums[i],mapping);
        vec.push_back({mappednum,i});
     }   
     sort(vec.begin() , vec.end());

     vector<int>result;
     for(auto it:vec)
     {
        int index=it.second;
        result.push_back(nums[index]);
     }
     return result;
    }
    
};