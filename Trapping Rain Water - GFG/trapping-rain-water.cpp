//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int height[], int n){
        long long res = 0;
        stack<int> decStack;
        for (int i = 0; i < n; i++)
        {
            while (decStack.size() && height[decStack.top()] <= height[i]) {
                int last = height[decStack.top()];
                decStack.pop();
                if(decStack.size()){
                    res += (min(height[decStack.top()], height[i]) - last) * (i - decStack.top() - 1);
                    last = height[decStack.top()];
                }
            }
            decStack.push(i);
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends