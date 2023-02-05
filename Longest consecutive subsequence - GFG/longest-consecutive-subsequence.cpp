//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    unordered_map<int, int> m;
    int findParent(int n){
        if(!m[n]){
            return 0;
        }
        else if(m[n] > 1){
            return m[n];
        }
        return m[n] = findParent(n + 1) + 1;
    }
    int findLongestConseqSubseq(int nums[], int n) {
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            m[nums[i]] = 1;
        }
        for (int i = 0; i < n; i++)
        {
            res = max(res, findParent(nums[i]));
        }
        return res;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends