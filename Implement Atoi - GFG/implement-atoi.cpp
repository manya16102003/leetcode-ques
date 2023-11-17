//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        //Your code here
        int num=0;
        int sign=1;
        int i=0;
        while(s[i]==' ')
        {
            i++;
        }
        if(i<s.size()&&s[i]=='-'||s[i]=='+')
        {
            sign=s[i]=='-'?-1:1;
            i++;
        }
        while(i<s.size())
        {
            if(isdigit(s[i]))
            {
                if(num>INT_MAX/10||(num==INT_MAX/10&&s[i]>'7'))
                return sign==-1?INT_MIN:INT_MAX;
            }
            else
            {
                return -1;
            }
            num=num*10+(s[i]-'0');
            i++;
        }
        return num*sign;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends