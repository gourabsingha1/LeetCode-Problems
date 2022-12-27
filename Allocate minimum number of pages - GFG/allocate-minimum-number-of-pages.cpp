//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    int findPages(int A[], int N, int M){
        if(M > N) return -1;
        int l = *max_element(A, A+N), h = accumulate(A, A+N, 0);
        while(l <= h){
            int mid = h + (l-h)/2, sum = 0, curr = 1;
            for (int i = 0; i < N; i++)
            {
                sum += A[i];
                if(sum > mid){
                    curr++;
                    sum = A[i];
                }
            }
            if(curr > M){
                l = mid + 1;
            }
            else{
                h = mid - 1;
            }
        }
        return l;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends