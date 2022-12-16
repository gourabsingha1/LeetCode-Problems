//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    vector<string> keypad = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> possibleWords(int a[], int N) {
        if(N == 0){
            return {""};
        }
        int ch = a[0];
        int rest[N-1];
        for (int i = 0; i < N; i++) rest[i] = a[i+1];
        
        vector<string> temp = possibleWords(rest, N-1);
        vector<string> res;
        for(string &s : temp){
            for (int i = 0; i < keypad[ch - 2].length(); i++)
            {
                char c = keypad[ch - 2][i];
                res.push_back(c+s);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
// 456
// 4 + 56
// 4 = "ghi" // ch
// 56 = ["jm, jn, jo, km, kn,.."] // rest
// res = ["gjm", "gjn", "gjo",..]


//{ Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}
// } Driver Code Ends