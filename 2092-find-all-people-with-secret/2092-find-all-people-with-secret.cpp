// sort meetings according time to go in one direction
// if two meetings happen at the same time, this means if any person knows the secret
// it will be shared among all persons

class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[2] < b[2];
    }

    void dfs(int u, unordered_map<int, vector<int>>& adj, unordered_map<int, bool>& vis, unordered_map<int, bool>& knows) {
        vis[u] = 1, knows[u] = 1;
        for(auto& v : adj[u]) {
            if(!vis[v]) {
                dfs(v, adj, vis, knows);
            }
        }
    }

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<int> res;
        sort(meetings.begin(), meetings.end(), cmp);
        unordered_map<int, bool> knows;
        knows[0] = 1, knows[firstPerson] = 1;
        int i = 0, m = meetings.size();
        while(i < m) {
            int time = meetings[i][2], j = i, found = 0;
            unordered_map<int, vector<int>> adj;
            while(i < m && time == meetings[i][2]) {
                int p1 = meetings[i][0], p2 = meetings[i++][1];
                found |= knows[p1] | knows[p2];
                adj[p1].push_back(p2);
                adj[p2].push_back(p1);
            }

            if(found) {
                unordered_map<int, bool> vis;
                for (int k = j; k < i; k++)
                {
                    int p1 = meetings[k][0], p2 = meetings[k][1];
                    if(!vis[p1] && knows[p1] || !vis[p2] && knows[p2]) {
                        dfs(p1, adj, vis, knows);
                    }
                }
            }
        }
        
        for (int i = 0; i <= n; i++)
        {
            if(knows[i]) {
                res.push_back(i);
            }
        }
        return res;
    }
};