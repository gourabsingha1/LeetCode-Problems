//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int M = 1e9 + 7;
    int fib(int n){
        int one = 1, two = 1;
        for(int i=2; i<n; ++i){
            int temp = one;
            one = (one + two)%M;
            two = temp;
        }
        return one;
    }
    int countWays(int n)
    {
        return fib(n+1);
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends