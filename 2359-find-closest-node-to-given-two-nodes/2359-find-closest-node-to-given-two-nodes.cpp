class Solution {
public:
    void bfs(int node, vector<int> &dist1, int n, vector<vector<int>> &adj) {
        int level = 0;
        vector<bool> vis(n, 0);
        queue<int> q;
        q.push(node);
        while(q.size()){
            int t = q.size();
            while(t--){
                int x = q.front();
                q.pop();
                dist1[x] = level;
                vis[x] = 1;
                for(int &it : adj[x]){
                    if(!vis[it]){
                        q.push(it);
                    }
                }
            }
            level++;
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size(), res = -1, curr = INT_MAX;
        vector<int> dist1(n, -1), dist2(n, -1);
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++)
        {
            int u = i, v = edges[i];
            if(v != -1){
                adj[u].push_back(v);
            }
        }
        bfs(node1, dist1, n, adj);
        bfs(node2, dist2, n, adj);
        for (int i = 0; i < n; i++)
        {
            if(dist1[i] != -1 && dist2[i] != -1){
                if(max(dist1[i], dist2[i]) < curr){
                    curr = max(dist1[i], dist2[i]);
                    res = i;
                }
            }
        }
        return res;
    }
};