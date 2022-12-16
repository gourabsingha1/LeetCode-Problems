//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
        deque<string> powerSet(string s){
		    if(!s.size()) return {""};
            char ch = s[0];
            deque<string> temp = powerSet(s.substr(1));
            deque<string> res;
            for(string &t : temp){
                res.push_back(ch+t);
                res.push_back(t);
            }
            sort(res.begin(), res.end());
            return res;
		}
        vector<string> AllPossibleStrings(string s){
            vector<string> res;
            deque<string> dq = powerSet(s);
            dq.pop_front();
            for(auto &x : dq){
                res.push_back(x);
            }
            return res;
        }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends