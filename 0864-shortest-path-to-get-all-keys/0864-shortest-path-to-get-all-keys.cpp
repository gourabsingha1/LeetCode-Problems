class Solution {
public:
    vector<int> dir = {1, 0, -1, 0, 1}; // right, down, left, up

    int bfs(int keys, int x, int y, vector<string>& grid) {
        int res = 0;
        queue<vector<int>> q; // x, y, seen
        q.push({x, y, 0});
        unordered_map<string, bool> mp; // visited array of x, y, seen
        string first = to_string(x) + "*" + to_string(y) + "*" + to_string(0);
        mp[first] = 1;
        while(q.size()) {
            int t = q.size();
            while(t--) {
                x = q.front()[0], y = q.front()[1];
                int seen = q.front()[2];
                q.pop();
                if(seen == (1 << keys) - 1) { // all keys are found
                    return res;
                }

                for (int i = 0; i < 4; i++)
                {
                    int dx = x + dir[i], dy = y + dir[i + 1], dz = seen;
                    if(dx >= 0 && dy >= 0 && dx < grid.size() && dy < grid[0].size() && grid[dx][dy] != '#'){
                        if(islower(grid[dx][dy])) { // found key. add key
                            int val = grid[dx][dy] - 'a';
                            int mask = 1 << val;
                            dz |= mask;
                        }
                        else if(isupper(grid[dx][dy])) { // found lock
                            int val = grid[dx][dy] - 'A';
                            int mask = 1 << val;
                            if((dz & mask) == 0) { // key was not found
                                continue;
                            }
                        }
                        // found key | found lock with its key | is an empty cell
                        string memo = to_string(dx) + "*" + to_string(dy) + "*" + to_string(dz);                        
                        // check if cell is visited
                        if(mp.find(memo) == mp.end()) {
                            q.push({dx, dy, dz});
                            mp[memo] = 1;
                        }
                    }
                }
            }
            res++;
        }
        return -1;
    }

    int shortestPathAllKeys(vector<string>& grid) {
        int x, y, keys = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == '@'){
                    x = i, y = j;
                }
                else if(islower(grid[i][j])){
                    keys++;
                }
            }
        }
        return bfs(keys, x, y, grid);
    }
};