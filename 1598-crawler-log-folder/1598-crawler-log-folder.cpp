class Solution {
public:
    int minOperations(vector<string>& logs) {
        int n =logs.size();
        // stack<string>st;
        // int i=0;
        // while(i<n)
        // {
        //     if(logs[i]=="../")
        //     {
        //         if(!st.empty())
        //         {
        //             st.pop();
        //         }
        //         else
        //         {
        //             i++;
        //             continue;
        //         } 
        //     }
        //     else if(logs[i]=="./")
        //     {
        //         {
        //             i++;
        //             continue;
        //         } 
        //     }
        //     else st.push(logs[i]);
        //     i++;
        // }
        // return st.size();

        int track=0;
        for(int i=0;i<n;i++)
        {
            if(logs[i]=="../") track=max(0,track-1);
            else if(logs[i]!="./") track++;
        }
        return track;
    }
};