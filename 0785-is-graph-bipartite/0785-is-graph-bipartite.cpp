class Solution {
public:
    bool bfs(int i, vector<int>& color, vector<vector<int>>& adj){
        queue<int> q;
        q.push(i);
        while(q.size()){
            int u = q.front();
            q.pop();
            for(auto& v : adj[u]){
                if(color[v] == -1){
                    color[v] = 1 - color[u];
                    q.push(v); 
                }
                else if(color[v] == color[u]){
                    return 0;
                }
            }
        }
        return 1;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size(), res = 1;
        vector<int> color(n, -1);
        for(int i = 0; i < n; i++){
            if(color[i] == -1){
                color[i] = 0;
                if(!bfs(i, color, graph)) {
                    return 0;
                }
            }
        }
        return 1;
    }
};