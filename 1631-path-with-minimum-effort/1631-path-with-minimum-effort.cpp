// update the neighbour dist with max(prevDist, abs(heights[x][y] - heights[dx][dy]))

class Solution {
public:
    vector<int> dir = {1, 0, -1, 0, 1}; // right, down, left, up

    int dijkstra(int n, int m, vector<vector<int>>& heights){
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq; // dist, row, col
        pq.push({0, 0, 0});
        while(pq.size()){
            auto v = pq.top();
            pq.pop();
            int prev = v[0], x = v[1], y = v[2];
            for (int i = 0; i < 4; i++)
            {
                int dx = x + dir[i], dy = y + dir[i + 1];
                if(dx >= 0 && dy >= 0 && dx < n && dy < m){
                    int newEffort = max(prev, abs(heights[x][y] - heights[dx][dy]));
                    if(dist[dx][dy] > newEffort) {
                        pq.push({newEffort, dx, dy});
                        dist[dx][dy] = newEffort;
                    }
                }
            }
        }
        return dist[n - 1][m - 1];
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        return dijkstra(heights.size(), heights[0].size(), heights);
    }
};