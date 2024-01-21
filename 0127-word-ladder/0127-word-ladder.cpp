class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordlist) {
        queue<pair<string,int>>q;
        unordered_set<string>st(wordlist.begin(),wordlist.end());
        st.erase(beginWord);
        q.push({beginWord , 1});
        while(!q.empty())
        {
            string currnode=q.front().first;
            int currcount=q.front().second;
            q.pop();
            if(currnode==endWord) return currcount;
            for(int index=0;index<currnode.size();index++)
            {
                char originalchar=currnode[index];
                for(char ch='a' ;ch<='z';ch++)
                {
                    currnode[index]=ch;
                    if(st.find(currnode)!=st.end())
                    {
                        q.push({currnode , currcount+1});
                        st.erase(currnode);
                    }
                }
                currnode[index]=originalchar;
            }
        }
        return 0;
        
    }
};