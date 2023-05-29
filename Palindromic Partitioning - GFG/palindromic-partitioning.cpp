//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int helper(int ind, string &s, vector<int>& dp){
        if(ind == s.size()){
            return 0;
        }
        if(dp[ind] != -1) {
            return dp[ind];
        }
        int res = INT_MAX;
        for (int i = ind; i < s.size(); i++)
        {
            if(isPalindrome(s.substr(ind, i - ind + 1))){
                res = min(res, 1 + helper(i + 1, s, dp));
            }
        }
        return dp[ind] = res;
    }

    bool isPalindrome(string s){
        int i = 0, j = s.size() - 1;
        while(i < j){
            if(s[i++] != s[j--]) return 0;
        }
        return 1;
    }
    
    int palindromicPartition(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return helper(0, s, dp) - 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends