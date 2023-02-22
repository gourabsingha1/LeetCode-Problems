class Solution {
public:
    vector<int> dir = {0, 1, 0, -1, 0};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int res = 0;
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
        while(q.size()) {
            int t = q.size();
            while(t--) {
                auto [x, y] = q.front();
                q.pop();
                if(res && (x == 0 || y == 0 || x == maze.size() - 1 || y == maze[0].size() - 1)){
                    return res;
                }
                for (int i = 0; i < 4; i++)
                {
                    int dx = x + dir[i], dy = y + dir[i + 1];
                    if(dx >= 0 && dy >= 0 && dx < maze.size() && dy < maze[0].size() && maze[dx][dy] == '.'){
                        q.push({dx, dy});
                        maze[dx][dy] = '+';
                    }
                }
            }
            res++;
        }
        return -1;
    }
};