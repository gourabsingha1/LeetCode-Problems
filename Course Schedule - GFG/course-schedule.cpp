//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> topoSort(int n, vector<vector<int>> &adj){
        vector<int> res, indegree(n, 0); // indegree = no. of arrows directed towards
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            for(auto &it : adj[i]){
                indegree[it]++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int i = q.front();
            q.pop();
            res.push_back(i);
            for(auto &it : adj[i]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        return res;
    }
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) {
        vector<int> res;
        vector<vector<int>> adj(n);
        for (int i = 0; i < prerequisites.size(); i++)
        {
            int u = prerequisites[i][0], v = prerequisites[i][1];
            adj[v].push_back(u);
        }
        res = topoSort(n, adj);
        if(res.size() != n){
            return {};
        }
        return res;
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends