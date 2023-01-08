//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool res = 0;
    void dfs(int i, int j, int k, vector<vector<char>>& board, string &word){
        if(k == word.size()){
            res = 1;
            return;
        }
        if(i < 0 || j < 0 || i == board.size() || j == board[0].size() || board[i][j] != word[k]){
            return;
        }
        char c = board[i][j];
        board[i][j] = '#';
        dfs(i - 1, j, k + 1, board, word);
        dfs(i, j - 1, k + 1, board, word);
        dfs(i + 1, j, k + 1, board, word);
        dfs(i, j + 1, k + 1, board, word);
        board[i][j] = c;
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                dfs(i, j, 0, board, word);
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends