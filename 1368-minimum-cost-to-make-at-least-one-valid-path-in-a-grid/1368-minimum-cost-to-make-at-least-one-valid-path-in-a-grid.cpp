// if arrow is in support, weight = 0, else 1
// then find the shortest path with minimum cost

class Solution {
public:
    vector<int> dir = {1, 0, -1, 0, 1}; // down, left, up, right
    
    int dijkstra(vector<vector<int>>& grid){
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int> (m, 1e9));
        priority_queue <vector<int>, vector<vector<int>>, greater<>> pq;
        dist[0][0] = 0;
        pq.push({0, 0, 0}); // dist, node
        while(pq.size()){
            int prev = pq.top()[0], x = pq.top()[1], y = pq.top()[2];
            pq.pop();
            if (prev > dist[x][y]) continue; // pruning
            for (int i = 0; i < 4; i++)
            {
                int dx = x + dir[i], dy = y + dir[i + 1];
                if(dx >= 0 && dy >= 0 && dx < n && dy < m) {
                    int wt = findWeight(grid[x][y], i + 1);
                    if(dist[dx][dy] > prev + wt) {
                        dist[dx][dy] = prev + wt;
                        pq.push({dist[dx][dy], dx, dy});
                    }
                }
            }
        }
        return dist[n - 1][m - 1];
    }
    
    int findWeight(int givenDir, int goingDir) {
        return !(givenDir == 1 && goingDir == 4 || givenDir == 2 && goingDir == 2 || givenDir == 3 && goingDir == 1 || givenDir == 4 && goingDir == 3);
    }

    int minCost(vector<vector<int>>& grid) {
        return dijkstra(grid);
    }
};