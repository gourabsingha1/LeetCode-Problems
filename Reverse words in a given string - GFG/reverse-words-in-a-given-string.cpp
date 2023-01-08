//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int i = 0, j = 0, n = s.size();
        while(i < n){
            j = i;
            while(i < n && s[i] != '.') i++;
            reverse(s.begin() + j, s.begin() + i);
            i++;
        }
        return s;
    }
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends