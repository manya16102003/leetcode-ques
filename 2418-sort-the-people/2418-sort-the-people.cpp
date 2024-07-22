class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string>>map;
        for(int i=0;i<names.size();i++){
            map.push_back({heights[i],names[i]});
        }
        sort(map.begin(),map.end(),greater());
        vector<string>ans;
        for(auto x: map) ans.push_back(x.second);
        return ans;
    }
};