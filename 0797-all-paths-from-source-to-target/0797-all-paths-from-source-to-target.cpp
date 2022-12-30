class Solution {
public:
    void dfs(int i, vector<vector<int>> &graph, vector<int> &path, vector<vector<int>> &res){
        if(i == graph.size()-1){
            res.push_back(path);
            return;
        }
        for(auto &it : graph[i]){
            path.push_back(it);
            dfs(it, graph, path, res);
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path = {0};
        vector<vector<int>> res;
        dfs(0, graph, path, res);
        return res;
    }
};