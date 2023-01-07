class Solution {
public:
    void dfs(int i, int &res, vector<int> &color, vector<vector<int>> &adj){
        for(auto &it : adj[i]){
            if(color[it] == -1){
                color[it] = 1 - color[i];
                dfs(it, res, color, adj);
            }
            else if(color[it] == color[i]){
                res = 0;
                return;
            }
        }
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size(), res = 1;
        vector<int> color(n, -1);
        for(int i = 0; i < n; i++){
            if(color[i] == -1){
                color[i] = 0;
                dfs(i, res, color, graph);
                if(!res) return 0;
            }
        }
        return 1;
    }
};