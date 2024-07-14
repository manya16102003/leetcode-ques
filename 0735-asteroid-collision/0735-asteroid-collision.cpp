class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        vector<int>ans;
        int n =asteroids.size();
        for(int i=0;i<n ;i++)
        {
            if(asteroids[i]>0)
            {
                st.push(asteroids[i]);
            }
            else
            {
                while(!st.empty() && st.top()>0 && st.top()<abs(asteroids[i]))
                {
                        st.pop();

                }
                if(st.empty() || st.top()<0)
                st.push(asteroids[i]);

                else if (st.top()==abs(asteroids[i])) 
                st.pop();
            }
        }
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};