class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        int res = INT_MAX;
        unordered_set<int> adj[n + 1];
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].insert(edges[i][1]);
            adj[edges[i][1]].insert(edges[i][0]);
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                for (int k = j + 1; k <= n; k++)
                {
                    if(adj[i].count(j) && adj[i].count(k) && adj[j].count(k)){
                        int size = adj[i].size() + adj[j].size() + adj[k].size() - 6;
                        res = min(res, size);
                    }
                }
            }
        }
        if(res == INT_MAX) res = -1;
        return res;
    }
};