//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void bfs(int i, int &res, vector<int> &color, vector<vector<int>> &adj){
        queue<int> q;
        q.push(i);
        while(q.size()){
            int t = q.front();
            q.pop();
            for(auto &it : adj[t]){
                if(color[it] == -1){
                    color[it] = 1 - color[t];
                    q.push(it); 
                }
                else if(color[it] == color[t]){
                    res = 0;
                    return;
                }
            }
        }
    }
	bool isBipartite(int V, vector<int> graph[]){
        int n = V, res = 1;
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++){
            for(auto &x : graph[i]){
                adj[i].push_back(x);
            }
        }
        vector<int> color(n, -1);
        for(int i = 0; i < n; i++){
            if(color[i] == -1){
                color[i] = 0;
                bfs(i, res, color, adj);
                if(!res) return 0;
            }
        }
        return 1;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends