class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        unordered_map<int, bool> visFor, visBack;
        for (int i = 0; i < forbidden.size(); i++)
        {
            visFor[forbidden[i]] = 1;
            visBack[forbidden[i]] = 1;
        }
        int level = 0;
        queue<pair<int, int>> q;
        q.push({0, 0});
        visFor[0] = 1, visBack[0] = 1;
        while (q.size()) {
            int t = q.size();
            while (t--) {
                auto [y, flag] = q.front();
                q.pop();
                if(y == x) {
                    return level;
                }
                if(y + a < 6000 && !visFor[y + a]) {
                    q.push({y + a, 0});
                    visFor[y + a] = 1;
                }
                if(y - b >= 0 && !visBack[y - b] && !flag) {
                    q.push({y - b, 1});
                    visBack[y - b] = 1;
                }
            }
            level++;
        }
        return -1;
    }
};