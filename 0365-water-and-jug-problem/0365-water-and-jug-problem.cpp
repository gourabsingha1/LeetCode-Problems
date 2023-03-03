class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        unordered_map<int, bool> seen;
        vector<int> dir = {jug1Capacity, -jug1Capacity, jug2Capacity, -jug2Capacity};
        queue<int> q;
        q.push(0);
        seen[0] = 1;
        while(q.size()) {
            int x = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int dx = x + dir[i];
                if(dx > 0 && dx <= jug1Capacity + jug2Capacity && !seen[dx]) {
                    if(dx == targetCapacity) {
                        return 1;
                    }
                    q.push(dx);
                    seen[dx] = 1;
                }
            }
        }
        return 0;
    }
};