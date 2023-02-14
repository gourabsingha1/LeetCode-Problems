class Solution {
public:
    vector<string> res;
    void dfs(string u, unordered_map<string, priority_queue<string, vector<string>, greater<>>> &adj){
        while(adj[u].size()){
            string v = adj[u].top();
            adj[u].pop();
            dfs(v, adj);
        }
        res.push_back(u);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, priority_queue<string, vector<string>, greater<>>> adj;
        for (int i = 0; i < tickets.size(); i++)
        {
            adj[tickets[i][0]].push(tickets[i][1]);
        }
        dfs("JFK", adj);
        reverse(res.begin(), res.end());
        return res;
    }
};