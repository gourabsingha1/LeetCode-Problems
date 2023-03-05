//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
public:
    // space optimization
    int FindMaxSum(int arr[], int n) {
        int prev1 = arr[0], prev2 = 0;
        for (int i = 1; i < n; i++)
        {
            int take = arr[i] + prev2;
            int notTake = 0 + prev1;
            prev2 = prev1;
            prev1 = max(take, notTake);
        }
        return prev1;
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
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends