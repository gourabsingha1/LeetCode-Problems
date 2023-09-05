//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int maxIndexDiff(int A[], int N) 
    { 
        vector<pair<int, int>> numsInd;
        for (int i = 0; i < N; i++)
        {
            numsInd.push_back({A[i], i});
        }
        sort(numsInd.begin(), numsInd.end());
        int res = 0, mn = 1e9;
        for (int i = 0; i < N; i++)
        {
            mn = min(mn, numsInd[i].second);
            res = max(res, numsInd[i].second - mn);
        }
        return res;
    }
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends