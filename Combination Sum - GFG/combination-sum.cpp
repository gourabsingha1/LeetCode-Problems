//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
public:
    void helper(int B, int i, vector<int>& A, vector<int> v, vector<vector<int>> &res){
        if(B <= 0 || i == A.size()){
            if(!B) res.push_back(v);
            return;
        }
        v.push_back(A[i]);
        helper(B - A[i], i, A, v, res);
        v.pop_back();
        helper(B, i+1, A, v, res);
    }

    vector<vector<int>> combinationSum(vector<int>& A, int B) {
        sort(A.begin(), A.end());
        A.erase(unique(A.begin(), A.end()), A.end());
        vector<vector<int>> res;
        helper(B, 0, A, {}, res);
        return res;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends