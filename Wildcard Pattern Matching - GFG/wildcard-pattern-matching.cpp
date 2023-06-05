//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
        bool helper(int n, int m, string& s, string& p, vector<vector<int>>& dp) {
        if(m < 0) {
            return n < 0;
        }
        if(n < 0) {
            for (int i = 0; i <= m; i++)
            {
                if(p[i] != '*') return 0;
            }
            return 1;
        }
        if(dp[n][m] != -1) {
            return dp[n][m];
        }

        bool res = 0;
        if(s[n] == p[m] || p[m] == '?') {
            res = helper(n - 1, m - 1, s, p, dp);
        }
        else if(p[m] == '*') {
            for (int i = n + 1; i >= 0; i--)
            {
                res |= helper(i - 1, m - 1, s, p, dp);
            }
        }
        return dp[n][m] = res;
    }

    bool wildCard(string p, string s) {
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return helper(n - 1, m - 1, s, p, dp);
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends