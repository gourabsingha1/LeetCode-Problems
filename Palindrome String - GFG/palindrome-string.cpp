//{ Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int i = 0;
	int recurr(int n, string &s, char &a, char &b){
        if(i == n/2) return 1;
        if(a != b){
            return 0;
        }
        i++;
        return recurr(n, s, s[i], s[n-1-i]);
    }
	int isPalindrome(string S)
	{
	    return recurr(S.size(), S, S[0], S[S.size()-1]);
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