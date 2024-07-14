class Solution {
public:
    string countOfAtoms(string formula) {
        int n=formula.length();
        stack<unordered_map<string , int>>st;
        st.push(unordered_map<string , int>());
        int i=0;
        while(i<n)
        {
            if(formula[i]=='(')
            {
                st.push(unordered_map<string , int>());
                i++;
            }
            else if(formula[i]==')')
            {
                unordered_map<string , int>currmap=st.top();
                st.pop();
                i++;
                string multiplier;
                while(i<n &&isdigit(formula[i]))
                {
                    multiplier+=formula[i];
                    i++;
                }
                if(!multiplier.empty())
                {
                    int multi=stoi(multiplier);
                    for(auto&[atom , count]:currmap)
                    {
                        currmap[atom]=count*multi;
                    }

                }
                for(auto&[atom , count]:currmap)
                {
                    st.top()[atom]+=count;
                }
            }
            else
            {
                string curratom;
                curratom+=formula[i];
                i++;
                while(i<n && islower(formula[i]))
                {
                    curratom+=formula[i];
                    i++;
                }
                string currcount;
                while(i<n && isdigit(formula[i]))
                {
                    currcount+=formula[i];
                    i++;
                }
                int count=currcount.empty()?1:stoi(currcount);
                st.top()[curratom]+=count;
            }
        }
        map<string , int>sortedmap(st.top().begin(), st.top().end());
        string result;
        for(auto&[atom , count]:sortedmap)
        {
            result+=atom;
            if(count>1)
            {
                result+=to_string(count);
            }
        }
        return result;
    }
};