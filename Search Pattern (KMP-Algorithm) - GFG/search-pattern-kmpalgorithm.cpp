//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
public:
    vector<int> lps(string &s) {
        int n = s.size(), i = 1, prevLPS = 0;
        vector<int> LPS(n, 0);
        while(i < n){
            if(s[i] == s[prevLPS]){
                LPS[i] = prevLPS + 1;
                prevLPS++, i++;
            }
            else if(prevLPS == 0){
                LPS[i] = 0, i++;
            }
            else{
                prevLPS = LPS[prevLPS - 1];
            }
        }
        return LPS;
    }
    vector<int> search(string pat, string txt) {
        vector<int> res, LPS = lps(pat);
        int i = 0, j = 0;
        while(i < txt.size()){
            if(txt[i] == pat[j]){
                i++, j++;
            }
            else if(j == 0){
                i++;
            }
            else{
                j = LPS[j-1];
            }
            if(j == pat.size()){
                j = 0, i = i + 1 - pat.size();
                res.push_back(i);
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends