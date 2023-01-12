class Solution {
public:
    vector<vector<int>> createGraph(int n, vector<vector<int>>& edges){
        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }
    void dfs(int child, int parent, vector<vector<int>> &adj, string &labels, vector<int> &cnt, vector<int> &res){
        cnt[labels[child] - 'a'] = 1;
        for(auto &it : adj[child]){
            if(it == parent) continue;
            vector<int> counting(26, 0);
            dfs(it, child, adj, labels, counting, res);
            for (int i = 0; i < 26; i++)
            {
                cnt[i] += counting[i];
            }
        }
        res[child] = cnt[labels[child] - 'a'];
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> res(n), cnt(26, 0);
        vector<vector<int>> adj = createGraph(n, edges);
        dfs(0, -1, adj, labels, cnt, res);
        return res;
    }
};