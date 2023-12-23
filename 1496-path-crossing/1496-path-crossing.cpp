class Solution {
public:
    bool isPathCrossing(string path) {
        map<pair<int, int>, bool> vis;
        int x = 0, y = 0;
        vis[{0, 0}] = 1;
        for(auto& ch : path) {
            if(ch == 'N') {
                y++;
            }
            else if(ch == 'E') {
                x++;
            }
            else if(ch == 'S') {
                y--;
            }
            else {
                x--;
            }
            
            if(vis[{x, y}]) {
                return 1;
            }
            vis[{x, y}] = 1;
        }
        return 0;
    }
};