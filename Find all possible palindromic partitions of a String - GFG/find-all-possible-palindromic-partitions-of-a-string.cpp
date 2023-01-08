//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
      void dfs(int i, string p, string &s, vector<string> v, vector<vector<string>> &res){
        if(i == s.size()){
            if(isPalindrome(p)){
                v.push_back(p);
                res.push_back(v);
            }
            return;
        }
        if(isPalindrome(p)){
            v.push_back(p);
            string temp; temp += s[i];
            dfs(i + 1, temp, s, v, res);
            v.pop_back();
        }
        dfs(i + 1, p + s[i], s, v, res);
    }
    bool isPalindrome(string &s){
        if(!s.size()) return 0;
        int i = 0, j = s.size() - 1;
        while(i < j){
            if(s[i++] != s[j--]) return 0;
        }
        return 1;
    }
    vector<vector<string>> allPalindromicPerms(string s) {
        vector<vector<string>> res;
        dfs(0, "", s, {}, res);
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends