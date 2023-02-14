class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int res = INT_MIN, n = vals.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int i = 0; i < n; i++)
        {
            priority_queue<int> pq;
            for(auto &v : adj[i]){
                if(vals[v] > 0){
                    pq.push(vals[v]);
                }
            }
            int sum = vals[i], K = k;
            while(pq.size() && K--){
                sum += pq.top();
                pq.pop();
            }
            res = max(res, sum);
        }
        return res;
    }
};