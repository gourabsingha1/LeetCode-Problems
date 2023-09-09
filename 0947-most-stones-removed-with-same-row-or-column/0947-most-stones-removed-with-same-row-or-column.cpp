// we can only remove stones if they are connected
// stones lying on same row are connected. similarly for columms
// treat indices of stones as nodes of a graph
// return n - number of island
// because last node of each island cannot be removed

class Solution {
public:
    vector<int> dir = {1, 0, -1, 0, 1}; // right, down, left, up

    void dfs(vector<bool>& vis, int ind, vector<vector<int>>& stones){
        vis[ind] = 1;
        for (int i = 0; i < stones.size(); i++)
        {
            if(!vis[i] && (stones[ind][0] == stones[i][0] || stones[ind][1] == stones[i][1])) {
                dfs(vis, i, stones);
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int res = 0, n = stones.size(), cntIslands = 0;
        vector<bool> vis(n, 0);
        for (int i = 0; i < n; i++)
        {
            if(!vis[i]) {
                dfs(vis, i, stones);
                cntIslands++;
            }
        }
        return n - cntIslands;
    }
};