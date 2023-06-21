//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long countKdivPairs(int A[], int n, int K)
    {
        map<int, int> freq;
        for (int i = 0; i < n; i++)
        {
            freq[A[i] % K]++;
        }
        long long res = 0;
        for(auto& f : freq) {
            int x = f.first;
            if(2 * x == K || x == 0) {
                res += (1LL * freq[x] * (freq[x] - 1)) / 2;
            }
            else {
                res += 1LL * freq[x] * freq[K - x];
                freq[x] = 0, freq[K - x] = 0;
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
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int k;
		cin >> k;

        Solution ob;
		cout << ob. countKdivPairs(a, n , k) << "\n";



	}


	return 0;
}

// } Driver Code Ends