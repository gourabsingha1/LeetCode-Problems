class Solution
{
public:
    bool ans;
    void dfs(vector<int> adj[], int u, vector<int> &color, int c)
    {
        color[u] = c;
        for (auto v : adj[u])
        {
            if (color[v] == -1)
            {
                dfs(adj, v, color, c ^ 1);
            }
            else if (color[v] == color[u])
            {
                ans = false;
                return;
            }
        }
    }
    bool possibleBipartition(int n, vector<vector<int>> &d)
    {
        vector<int> adj[n + 1];
        for (int i = 0; i < d.size(); i++)
        {
            int u = d[i][0];
            int v = d[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        ans = true;
        vector<int> color(n + 1, -1);

        for (int i = 1; i <= n; i++)
        {
            if (color[i] == -1)
            {
                dfs(adj, i, color, 0);
            }
        }

        return ans;
    }
};