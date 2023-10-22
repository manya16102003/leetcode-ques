class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int carry=0;
        int n=num.size();
        
        vector<int>ans;
        for(int i=n-1;i>=0;i--)
        {
            int x=num[i]+k%10+carry;
            int digit=x%10;
            carry=x/10;
            k=k/10;
            ans.push_back(digit);
        }
        while(k!=0)
        {
            int x=k%10+carry;
            int digit=x%10;
            carry=x/10;
            k=k/10;
            ans.push_back(digit);
        }
        if(carry!=0)
        {
            ans.push_back(carry);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};