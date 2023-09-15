class Solution {
public:
    void helper(string u, unordered_map<string, queue<string>>& adj, vector<string>& res) {
        while(adj[u].size()) {
            string v = adj[u].front();
            adj[u].pop();
            helper(v, adj, res);
        }
        res.push_back(u);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.begin(), tickets.end());
        unordered_map<string, queue<string>> adj;
        for(auto& ticket : tickets) {
            adj[ticket[0]].push(ticket[1]);
        }
        vector<string> res;
        helper("JFK", adj, res);
        reverse(res.begin(), res.end());
        return res;
    }
};