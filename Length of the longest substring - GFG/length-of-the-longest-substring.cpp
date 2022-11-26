//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string s){
        int res = 0;
        vector<int> m(26, 0);
        int j = 0;
        for (int i = 0; i < s.size(); i++)
        {
            while(m[s[i]-'a']){
                m[s[j]-'a']--;
                j++;
            }
            res = max(res, i-j+1);
            m[s[i]-'a']++;
        }
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends