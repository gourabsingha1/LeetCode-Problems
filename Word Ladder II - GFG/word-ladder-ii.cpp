//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        unordered_map<string, bool> m;
        for(auto &s : wordList) m[s] = 1;
        queue<vector<string>> q;
        q.push({beginWord});
        while(q.size()){
            int t = q.size();
            vector<string> removeLater;
            while(t--){
                vector<string> v = q.front();
                q.pop();
                string s = v.back();
                if(s == endWord){
                    if(!res.size() || res[0].size() == v.size()){
                        res.push_back(v);
                    }
                    else{
                        return res;
                    }
                }
                m[s] = 0;
                for (int i = 0; i < beginWord.size(); i++)
                { 
                    char temp = s[i];
                    for (char c = 'a'; c <= 'z'; c++)
                    {
                        s[i] = c;
                        if(m[s]){
                            v.push_back(s);
                            q.push(v);
                            v.pop_back();
                            removeLater.push_back(s);
                        }
                    }
                    s[i] = temp;
                }
            }
            for(auto &s : removeLater){
                m[s] = 0;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends