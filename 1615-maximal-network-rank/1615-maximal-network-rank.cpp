class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int res = 0;
        vector<vector<int>> adj(n);
        for (int i = 0; i < roads.size(); i++)
        {
            int u = roads[i][0], v = roads[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int cnt = adj[i].size() + adj[j].size();
                for(auto &v : adj[j]){
                    if(v == i){
                        cnt--;
                        break;
                    }
                }
                res = max(res, cnt);
            }
        }
        return res;
    }
};