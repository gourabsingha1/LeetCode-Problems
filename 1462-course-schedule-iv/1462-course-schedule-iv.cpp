class TopologicalSortDFS{
public:
    void dfs(int u, vector<bool> &vis, stack<int> &st, vector<vector<int>> &adj){
        vis[u] = 1;
        for(auto &v : adj[u]){
            if(!vis[v]){
                dfs(v, vis, st, adj);
            }
        }
        st.push(u);
    }
    vector<int> topoSort(int n, vector<vector<int>> &adj){
        vector<int> res;
        stack<int> st;
        vector<bool> vis(n);
        for (int i = 0; i < n; i++)
        {
            if(!vis[i]){
                dfs(i, vis, st, adj);
            }
        }
        while(st.size()){
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};
class Solution {
public:
    bool bfs(int src, int dest, int n, vector<vector<int>> &adj) {
        vector<bool> vis(n);
        queue<int> q;
        q.push(src);
        while(q.size()){
            int t = q.front();
            if(t == dest){
                return 1;
            }
            q.pop();
            for(int &x : adj[t]){
                if(!vis[x]){
                    q.push(x);
                    vis[x] = 1;
                }
            }
        }
        return 0;
    }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<bool> res(queries.size());
        if(!prerequisites.size()){
            return res;
        }
        vector<vector<int>> adj(n);
        for (int i = 0; i < prerequisites.size(); i++)
        {
            int u = prerequisites[i][0], v = prerequisites[i][1];
            adj[u].push_back(v);
        }
        TopologicalSortDFS TOPO;
        vector<int> topo = TOPO.topoSort(n, adj);
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            m[topo[i]] = i;
        }
        for (int i = 0; i < queries.size(); i++)
        {
            int src = queries[i][0], dest = queries[i][1];
            if(bfs(src, dest, n, adj)){
                res[i] = m[queries[i][0]] < m[queries[i][1]];
            }
        }
        return res;
    }
};