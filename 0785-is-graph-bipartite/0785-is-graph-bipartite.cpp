class Solution {
public:
    void bfs(int i, int &res, vector<int> &color, vector<vector<int>> &adj){
        queue<int> q;
        q.push(i);
        while(q.size()){
            int t = q.front();
            q.pop();
            for(auto &it : adj[t]){
                if(color[it] == -1){
                    color[it] = 1 - color[t];
                    q.push(it); 
                }
                else if(color[it] == color[t]){
                    res = 0;
                    return;
                }
            }
        }
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size(), res = 1;
        vector<int> color(n, -1);
        for(int i = 0; i < n; i++){
            if(color[i] == -1){
                color[i] = 0;
                bfs(i, res, color, graph);
                if(!res) return 0;
            }
        }
        return 1;
    }
};