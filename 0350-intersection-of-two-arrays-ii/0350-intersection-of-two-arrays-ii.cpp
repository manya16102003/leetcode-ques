class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
       int n=nums1.size();
       int m=nums2.size();
       unordered_map<int , int>mp, mp2;
       for(int i=0;i<n;i++)
       {
        mp[nums1[i]]++;
       }

       for(int j=0;j<m;j++){
        if(mp.find(nums2[j])!=mp.end()){
            mp2[nums2[j]]++;
            mp2[nums2[j]]=min(mp[nums2[j]] , mp2[nums2[j]]);
        }
       }

       for(auto i:mp2){
        while(i.second!=0){
            ans.push_back(i.first);
            i.second--;
        }
       }
        return ans;
    }
};