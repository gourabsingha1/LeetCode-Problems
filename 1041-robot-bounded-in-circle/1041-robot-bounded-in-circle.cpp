// L: N, W, S, E
// R: N, E, S, W
// last position should be origin or it shouldn't face north

class Solution {
public:
    vector<int> dir[4] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}}; // N, W, S, E

    bool isRobotBounded(string instructions) {
        int x = 0, y = 0, i = 0;
        for(auto& ch : instructions) {
            if(ch == 'L') {
                i = (i + 1) % 4;
            }
            else if(ch == 'R') {
                i = (i + 3) % 4;
            }
            else {
                x += dir[i][0], y += dir[i][1];
            }
        }

        return x == 0 && y == 0 || i > 0;
    }
};