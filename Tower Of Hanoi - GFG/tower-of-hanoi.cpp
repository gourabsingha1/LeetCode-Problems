//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // You need to complete this function

    long long toh(int N, int from, int to, int aux) {
        if(N <= 0) {
            return 0;
        }
        // let, N = 3
        int res = 1 + toh(N - 1, from, aux, to); // (2, 1, 2, 3)
        cout<<"move disk "<<N<<" from rod "<<from<<" to rod "<<to<<endl; // 1 -> 3
        res += toh(N - 1, aux, to, from); // (2, 2, 3, 1)
        return res;
    }

};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;//testcases
    while (T--) {
        
        int N;
        cin >> N;//taking input N
        
        //calling toh() function
        Solution ob;
        
        cout << ob.toh(N, 1, 3, 2) << endl;
    }
    return 0;
}


//Position this line where user code will be pasted.
// } Driver Code Ends