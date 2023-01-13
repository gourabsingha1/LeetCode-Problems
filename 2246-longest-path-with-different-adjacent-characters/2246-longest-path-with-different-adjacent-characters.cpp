class Solution {
public:
    vector<vector<int>> createGraph(int n, vector<int>& parent){
        vector<vector<int>> adj(n);
        for (int i = 1; i < parent.size(); i++)
        {
            int u = parent[i], v = i;
            adj[u].push_back(v);
        }
        return adj;
    }
    int dfs(int i, vector<vector<int>>& adj, string& s, int& res) {
        int longest = 0, secondLongest = 0;
        for (auto &it : adj[i]) {
            int curr = dfs(it, adj, s, res);
            if(s[i] == s[it]) continue;
            if (curr > longest) {
                secondLongest = longest;
                longest = curr;
            }
            else if (curr > secondLongest) {
                secondLongest = curr;
            }
        }
        res = max(res, longest + secondLongest + 1);
        return longest + 1;
    }

    int longestPath(vector<int>& parent, string s) {
        int res = 0, n = parent.size();
        vector<vector<int>> adj = createGraph(n, parent);
        dfs(0, adj, s, res);
        return res;
    }
};