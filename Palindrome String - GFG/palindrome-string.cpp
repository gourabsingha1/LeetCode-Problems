//{ Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int recurr(int i, int j, string &s){
        if(i >= j) return 1;
        if(s[i] != s[j]){
            return 0;
        }
        return recurr(i+1, j-1, s);
    }
	int isPalindrome(string S)
	{
	    return recurr(0, S.size()-1, S);
	}
};

//{ Driver Code Starts.

int main() 
{
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.isPalindrome(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends