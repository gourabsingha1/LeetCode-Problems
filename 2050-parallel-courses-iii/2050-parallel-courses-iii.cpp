// dp[i] = maxTime till ith node

class Solution {
public:
    int dfs(int u, vector<int> adj[], vector<int>& time, vector<int>& dp) {
        if(dp[u]) {
            return dp[u];
        }

        int res = time[u - 1];
        for(auto& v : adj[u]) {
            res = max(res, time[u - 1] + dfs(v, adj, time, dp));
        }
        return dp[u] = res;
    }

    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> adj[n + 1], indegree(n + 1, 0);
        for(auto& edge : relations) {
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }

        vector<int> dp(n + 1, 0);
        for (int u = 1; u <= n; u++)
        {
            if(indegree[u] == 0) {
                dfs(u, adj, time, dp);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};