class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int res = 0;
        vector<int> adj[n];
        for (int i = 0; i < roads.size(); i++)
        {
            int u = roads[i][0], v = roads[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int u = 0; u < n; u++)
        {
            for (int v = u + 1; v < n; v++)
            {
                int cur = adj[u].size() + adj[v].size();
                for(auto& vNode : adj[v]){
                    if(vNode == u){
                        cur--;
                        break;
                    }
                }
                res = max(res, cur);
            }
        }
        return res;
    }
};