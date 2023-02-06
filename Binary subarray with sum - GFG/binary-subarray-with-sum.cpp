//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0, n = nums.size(), pre = 0;
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            pre += nums[i];
            if(pre == k){
                res++;
            }
            res += m[pre - k];
            m[pre]++;
        }
        return res;
    }
    int numberOfSubarrays(vector<int>& nums, int n, int goal){
        return subarraySum(nums, goal);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int target; 
        cin >> target;
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin >> arr[i];
        Solution obj;
        cout<<obj.numberOfSubarrays(arr, N, target)<<endl;
    }
    return 0;
}
// } Driver Code Ends