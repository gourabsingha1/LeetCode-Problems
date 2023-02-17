class DisjointSet{
public:
    vector<int> parent, rank;
    DisjointSet(int n){
        parent.resize(n + 1), rank.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    int findParent(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findParent(parent[node]); // path compression
    }
    bool Union(int u, int v){
        u = findParent(u);
        v = findParent(v);
        if(u == v){
            return 1;
        }
        if(rank[u] < rank[v]){
            parent[u] = v;
        }
        else if(rank[u] > rank[v]){
            parent[v] = u;
        }
        else{
            parent[v] = u;
            rank[u]++;
        }
        return 0;
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> res;
        int n = accounts.size();
        DisjointSet DSU(n);
        unordered_map<string, int> m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < accounts[i].size(); j++)
            {
                int ind = m[accounts[i][j]];
                if(ind){
                    if(accounts[ind - 1][0] == accounts[i][0]){
                        DSU.Union(ind - 1, i);
                    }
                }
                else{
                    m[accounts[i][j]] = i + 1;
                }
            }
        }
        unordered_map<int, set<string>> mp;
        for (int i = 0; i < n; i++)
        {
            int ind = DSU.findParent(i);
            for (int j = 1; j < accounts[i].size(); j++)
            {
                mp[ind].insert(accounts[i][j]);
            }
        }
        for(auto &[i, st] : mp){
            vector<string> temp = {accounts[i][0]};
            for(auto &s : st){
                temp.push_back(s);
            }
            res.push_back(temp);
        }
        return res;
    }
};