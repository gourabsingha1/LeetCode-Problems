//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool helper(int n, int sum, vector<int>& nums, vector<vector<int>>& dp) {
        if(!sum) {
            return 1;
        }
        if(n < 0 || sum < 0) {
            return 0;
        }
        if(dp[n][sum] != -1) {
            return dp[n][sum];
        }
        bool take = helper(n - 1, sum - nums[n], nums, dp);
        bool notTake = helper(n - 1, sum, nums, dp);
        return dp[n][sum] = take || notTake;
    }
    bool isSubsetSum(vector<int> nums, int sum){
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (sum + 1, -1));
        return helper(n - 1, sum, nums, dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends