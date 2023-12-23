#define ll long long

class Solution {
public:
    pair<multiset<ll>, multiset<ll>> dfs(int u, int par, vector<ll> adj[], vector<int>& cost, vector<ll>& coin) {
        multiset<ll> st, negs;
        if(cost[u] < 0) negs.insert(-cost[u]);
        else st.insert(cost[u]);
        
        for(auto& v : adj[u]) {
            if(v == par) continue;

            auto [cur, cur2] = dfs(v, u, adj, cost, coin);
            for(auto& x : cur) {
                st.insert(x);
                if(st.size() > 3) {
                    st.erase(st.begin());
                }
            }
            for(auto& x : cur2) {
                negs.insert(x);
                if(negs.size() > 3) negs.erase(negs.begin());
            }
        }

        
        if(st.size() >= 3) {
            ll prod = 1;
            for(auto& x : st) {
                prod *= x;
            }
            coin[u] = prod;
        }
        if(st.size() && negs.size() >= 2) {
            ll prod = *prev(st.end()) * (*prev(negs.end())) * (*prev(prev(negs.end())));
            coin[u] = max(coin[u], prod);
        }
        if(negs.size() == 3) {
            coin[u] = max(coin[u], 0LL);
        }
        if(st.size() + negs.size() < 3){
            coin[u] = 1;
        }
        return {st, negs};
    }

    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
        int n = cost.size();
        vector<ll> adj[n];
        for (int i = 0; i < n - 1; i++)
        {
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<ll> coin(n, 0);
        dfs(0, -1, adj, cost, coin);
        return coin;
    }
};