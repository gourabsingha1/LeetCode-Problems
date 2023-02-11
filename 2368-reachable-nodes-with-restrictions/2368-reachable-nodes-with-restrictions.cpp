class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        int res = 0;
        vector<int> adj[n];
        vector<bool> vis(n), m(n);
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int i = 0; i < restricted.size(); i++)
        {
            m[restricted[i]] = 1;
        }
        queue<int> q;
        q.push(0);
        while(q.size()){
            int t = q.size();
            while(t--){
                res++;
                int u = q.front();
                vis[u] = 1;
                q.pop();
                for(auto &v : adj[u]){
                    if(!m[v] && !vis[v]){
                        q.push(v);
                    }
                }
            }
        }
        return res;
    }
};