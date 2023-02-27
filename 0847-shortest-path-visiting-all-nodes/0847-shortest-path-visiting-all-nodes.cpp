struct node {
    int x, mask, cost = 1e9;
};
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size(), full = (1 << n) - 1;
        if (n == 1) return 0;
        queue<node> q;
        node start{0, 1, 0};
        set<pair<int, int>> usd;
        for(int i = 0 ; i < n; i++){
            int mask = (1 << i);
            q.push({i, mask, 0});
            usd.insert({i,mask});
        }
        while (q.size()) {
            node cur = q.front();
            q.pop();
            for (int i = 0; i < graph[cur.x].size(); i++) {
                int y = graph[cur.x][i];
                node temp {y, cur.mask | (1 << y), cur.cost + 1};
                if (temp.mask == full){
                    return temp.cost;
                }
                pair<int, int> cords = {temp.x, temp.mask};
                if (!usd.count(cords)) {
                    usd.insert(cords);
                    q.push(temp);
                }
            }
        }
        return -1;
    }
};