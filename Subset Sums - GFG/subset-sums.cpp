//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution
{
public:
    void helper(int currInd, vector<int> &arr, int sum, vector<int> &res){
        if(currInd == arr.size()){
            res.push_back(sum);
            return;
        }
        helper(currInd + 1, arr, sum, res);
        helper(currInd + 1, arr, sum + arr[currInd], res);
    }
    vector<int> subsetSums(vector<int> arr, int N){
        vector<int> res;
        helper(0, arr, 0, res);
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
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends