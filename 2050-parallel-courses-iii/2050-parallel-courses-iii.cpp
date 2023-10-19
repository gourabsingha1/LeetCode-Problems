class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> adj[n + 1], indegree(n + 1, 0);
        for(auto& edge : relations) {
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
        queue<int> q;
        vector<int> maxTime(n + 1, 0);
        for (int u = 1; u <= n; u++)
        {
            if(indegree[u] == 0) {
                q.push(u);
                maxTime[u] = time[u - 1];
            }
        }
        
        while(q.size()) {
            int size = q.size();
            while(size--) {
                int u = q.front();
                q.pop();
                for(auto& v : adj[u]) {
                    maxTime[v] = max(maxTime[v], maxTime[u] + time[v - 1]);
                    if(--indegree[v] == 0) {
                        q.push(v);
                    }
                }
            }
        }
        return *max_element(maxTime.begin(), maxTime.end());
    }
};