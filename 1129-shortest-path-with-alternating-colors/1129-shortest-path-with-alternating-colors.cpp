class Solution {
public:
    vector<int> bfs(int src, int n, vector<int> red[], vector<int> blue[]){
        vector<int> dist(n, -1);
        vector<vector<bool>> vis(2, vector<bool> (n));
        queue<vector<int>> q; // node, length, color
        q.push({src, 0, 1}); // 0 = blue, 1 = red
        q.push({src, 0, 0});
        while(q.size()){
            int u = q.front()[0], length = q.front()[1], prev = q.front()[2];
            q.pop();
            vis[prev][u] = 1;
            if(dist[u] == -1){
                dist[u] = length;
            }
            if(prev){
                for(auto &v : blue[u]){
                    if(!vis[0][v]){
                        q.push({v, length + 1, 0});
                    }
                }
            }
            else{
                for(auto &v : red[u]){
                    if(!vis[1][v]){
                        q.push({v, length + 1, 1});
                    }
                }
            }
        }
        return dist;
    }
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> red[n], blue[n];
        for (int i = 0; i < redEdges.size(); i++)
        {
            int u = redEdges[i][0], v = redEdges[i][1];
            red[u].push_back(v);
        }
        for (int i = 0; i < blueEdges.size(); i++)
        {
            int u = blueEdges[i][0], v = blueEdges[i][1];
            blue[u].push_back(v);
        }
        return bfs(0, n, red, blue);
    }
};
