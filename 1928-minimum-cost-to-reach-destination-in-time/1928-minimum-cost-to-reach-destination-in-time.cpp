// keep track of minimum cost and minimum time till a particular node from node 0
// if current time is within the maxTime, add in the queue
// prioritize cost first. if new cost is less, then cost[v] is updated but time[v] is not updated
// because there may be a different path where it takes less time to reach

class Solution {
public: 
    int dijkstra(int n, int maxTime, vector<vector<int>> adj[], vector<int>& passingFees) {
        vector<int> cost(n, 1e9), time(n, 1e9);
        cost[0] = passingFees[0], time[0] = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({passingFees[0], 0, 0}); // cost, time, node
        while(pq.size()) {
            auto node = pq.top();
            int prevFees = node[0], prevTime = node[1], u = node[2];
            pq.pop();
            for(auto& it : adj[u]) {
                int v = it[0], curTime = it[1], curFees = passingFees[v];
                if(prevTime + curTime <= maxTime) {
                    if(cost[v] > prevFees + curFees) {
                        cost[v] = prevFees + curFees;
                        pq.push({cost[v], prevTime + curTime, v});
                    }
                    else if(time[v] > prevTime + curTime) {
                        time[v] = prevTime + curTime;
                        pq.push({prevFees + curFees, time[v], v});
                    }
                }
            }
        }
        if(cost[n - 1] == 1e9) {
            return -1;
        }
        return cost[n - 1];
    }
    
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        vector<vector<int>> adj[n];
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0], v = edges[i][1], time = edges[i][2];
            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }
        return dijkstra(n, maxTime, adj, passingFees);
    }
};