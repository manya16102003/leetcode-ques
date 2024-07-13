class Solution {
public:
string removestr(string s , string  &matchstr)
{
    stack<char>st;
    for(char &ch:s)
    {
        if(ch==matchstr[1] && !st.empty() && st.top()==matchstr[0])
        {
            st.pop();
        }
        else
        {
            st.push(ch);
        }
    }
    string temp;
    while(!st.empty())
    {
        temp.push_back(st.top());
        st.pop();
    }
    reverse(temp.begin() , temp.end());
    return temp;
     
}
    int maximumGain(string s, int x, int y) {
        int n =s.length();
        int score=0;
        string maxstr=(x>y)?"ab":"ba";
        string minstr=(x<y)?"ab":"ba";
        string temp_first=removestr(s , maxstr);
        int L=temp_first.length();
        int charremoved=n-L;
        score+=(charremoved/2)*max(x,y);

        string temp_second=removestr(temp_first , minstr);
        charremoved=L-temp_second.length();

        score+=(charremoved/2)*min(x,y);
        return score;

    }
};