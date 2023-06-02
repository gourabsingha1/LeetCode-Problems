// d(r1, r2) <= r1
// if bomb1 detonates bomb2, it doesnt mean bomb2 will also detonate bomb1
// dfs to check maximum connected bombs

class Solution {
public:
    double findDist(int x1, int y1, int x2, int y2) {
        return sqrt(pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2));
    }

    int dfs(int u, vector<bool>& vis, vector<int> adj[]) {
        vis[u] = 1;
        int res = 0;
        for(auto&v : adj[u]) {
            if(vis[v]) continue;
            res += 1 + dfs(v, vis, adj);
        }
        return res;
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size(), res = 0;
        vector<int> adj[n];
        for (int i = 0; i < n; i++)
        {
            int x1 = bombs[i][0], y1 = bombs[i][1], r1 = bombs[i][2];
            for (int j = i + 1; j < n; j++)
            {
                int x2 = bombs[j][0], y2 = bombs[j][1], r2 = bombs[j][2];
                double dist = findDist(x1, y1, x2, y2);
                if(dist <= r1) {
                    adj[i].push_back(j);
                }
                if(dist <= r2) {
                    adj[j].push_back(i);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            vector<bool> vis(n, 0);
            res = max(res, dfs(i, vis, adj) + 1);
        }
        return res;
    }
};