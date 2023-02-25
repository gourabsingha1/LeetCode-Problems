class Solution {
public:
    int bfs(int n, vector<int> adj[], int headID, vector<int>& informTime) {
        int res = 0;
        queue<pair<int, int>> q;
        q.push({headID, 0});
        while(q.size()){
            int t = q.size();
            while(t--){
                auto [u, wt] = q.front();
                q.pop();
                res = max(res, wt);
                for(int &v : adj[u]){
                    q.push({v, wt + informTime[u]});
                }
            }
        }
        return res;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> adj[n];
        for (int i = 0; i < n; i++)
        {
            if(manager[i] != -1){
                int u = i, v = manager[i];
                adj[v].push_back(u);
            }
        }
        return bfs(n, adj, headID, informTime);
    }
};