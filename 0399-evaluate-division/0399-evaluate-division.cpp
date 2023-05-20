class Solution {
public:
    struct node
    {
        string var;
        double val;
    };

    void dfs(bool& found, double& res, double cur, string& u, string& dst, unordered_map<string, bool>& vis, unordered_map<string, vector<node>>& adj) {
        vis[u] = 1;
        for(auto& v: adj[u]) {
            if(vis[v.var]) continue;
            if(v.var == dst) {
                found = 1;
                res = cur * v.val;
                return;
            }
            dfs(found, res, cur * v.val, v.var, dst, vis, adj);
        }
        return;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> res;
        unordered_map<string, vector<node>> adj;
        unordered_map<string, bool> seen;
        for (int i = 0; i < equations.size(); i++)
        {
            string var1 = equations[i][0], var2 = equations[i][1];
            adj[var1].push_back({var2, values[i]});
            adj[var2].push_back({var1, 1 / values[i]});
            seen[var1] = seen[var2] = 1;
        }
        for(auto&q : queries) {
            string var1 = q[0], var2 = q[1];
            if(var1 == var2) {
                if(seen[var1]) {
                    res.push_back(1);
                }
                else {
                    res.push_back(-1);
                }
                continue;
            }
            unordered_map<string, bool> vis;
            double ans = 1;
            bool found = 0;
            dfs(found, ans, 1, var1, var2, vis, adj);
            res.push_back(ans);
            if(!found) {
                res.back() = -1;
            }
        }
        return res;
    }
};