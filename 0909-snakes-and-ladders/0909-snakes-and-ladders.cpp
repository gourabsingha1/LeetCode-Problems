class Solution
{
public:
    int snakesAndLadders(vector<vector<int>> &board)
    {
        queue<pair<int, int>> q;
        int n = board.size();
        vector<int> vis((n * n) + 1, 0);
        q.push({1, 0});
        vis[1] = 1;
        int x = n - 1;
        int y = 0;
        unordered_map<int, pair<int, int>> mp;
        for (int i = 1; i <= n * n; i++)
        {
            int ch = (i / n) % 2;
            int up = !(i % n);
            mp[i] = {x, y};
            if (ch == 0 && !up) y++;
            else if (ch == 1 && !up) y--;
            else if (up) x--;
        }
        while (!q.empty())
        {
            int curr = q.front().first;
            int st = q.front().second;
            q.pop();
            if (curr == n * n) return st;
            int count = 0;
            for (int i = curr + 1; i <= min(curr + 6, n * n); i++)
            {
                if (!vis[i])
                {
                    int x = mp[i].first;
                    int y = mp[i].second;
                    if (board[x][y] != -1){
                        q.push({board[x][y], st + 1});
                    }
                    else{
                        q.push({i, st + 1});
                    }
                    vis[i] = 1;
                }
            }
        }
        return -1;
    }
};