class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        int res = INT_MAX;
        int adj[401][401] = {}, deg[401] = {};
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0], v = edges[i][1];
            adj[u][v] = 1;
            adj[v][u] = 1;
            deg[u]++, deg[v]++;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if(!adj[i][j]) continue;
                for (int k = j + 1; k <= n; k++)
                {
                    if(adj[i][k] && adj[j][k]){
                        res = min(res, deg[i] + deg[j] + deg[k] - 6);
                    }
                }
            }
        }
        if(res == INT_MAX) res = -1;
        return res;
    }
};