//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = beginWord.size(), res = 0;
        unordered_map<string, bool> m;
        for(auto &s : wordList) m[s] = 1;
        queue<string> q;
        q.push(beginWord);
        while(q.size()){
            res++;
            int t = q.size();
            while(t--){
                string s = q.front();
                if(s == endWord){
                    return res;
                }
                q.pop();
                m[s] = 0;
                for (int i = 0; i < n; i++)
                {
                    char temp = s[i];
                    for (int j = 0; j < 26; j++)
                    {
                        s[i] = 'a' + j;
                        if(m[s]){
                            q.push(s);
                            m[s] = 0;
                        }
                    }
                    s[i] = temp;
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
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
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends