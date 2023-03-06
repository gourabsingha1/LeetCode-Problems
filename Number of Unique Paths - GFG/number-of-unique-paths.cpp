//{ Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution
{
    public:
    // space optimization
    int NumberOfPath(int n, int m)
    {
        vector<int> prev(m, 0);
        for (int i = 0; i < n; i++)
        {
            vector<int> curr(m, 0);
            for (int j = 0; j < m; j++)
            {
                if(i == 0 && j == 0) {
                    curr[j] = 1;
                }
                else {
                    int up = 0, left = 0;
                    if(i > 0) {
                        up = prev[j];
                    }
                    if(j > 0) {
                        left = curr[j - 1];
                    }
                    curr[j] = up + left;
                }
            }
            prev = curr;
        }
        return prev[m - 1];
    }
};


//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}


// } Driver Code Ends