//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int maxIndexDiff(int a[], int n) 
    { 
        vector<int> pre(n), suf(n);
        pre[0] = a[0], suf[n - 1] = a[n - 1];
        for (int i = 1; i < n; i++)
        {
            pre[i] = min(a[i], pre[i - 1]);
        }
        for (int i = n - 2; i >= 0; i--)
        {
            suf[i] = max(a[i], suf[i + 1]);
        }
        int res = 0, i = 0, j = 0;
        while(i < n && j < n) {
            if(pre[i] <= suf[j]) {
                res = max(res, j - i);
                j++;
            }
            else {
                i++;
            }
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