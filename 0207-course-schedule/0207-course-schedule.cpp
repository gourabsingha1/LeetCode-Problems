class Solution {
public:
    bool dfs(int i, vector<bool> &vis, vector<bool> &dfsVis, vector<vector<int>> &adj){
        vis[i] = 1;
        dfsVis[i] = 1;
        for(auto &it : adj[i]){
            if(!vis[it]){
                if(dfs(it, vis, dfsVis, adj)){
                    return 1;
                }
            }
            else if(dfsVis[it]){
                return 1;
            }
        }
        dfsVis[i] = 0;
        return 0;
    }
    bool isCyclic(int n, vector<vector<int>> &adj){
        vector<bool> vis(n, 0); // to mark all time visited paths
        vector<bool> dfsVis(n, 0); // to mark the current visited path
        for (int i = 0; i < n; i++)
        {
            if(!vis[i]){
                if(dfs(i, vis, dfsVis, adj)){
                    return 1;
                }
            }
        }
        return 0;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.size() == 1) return 1;
        vector<vector<int>> adj(numCourses);
        for (int i = 0; i < prerequisites.size(); i++)
        {
            int u = prerequisites[i][0], v = prerequisites[i][1];
            adj[u].push_back(v);
        }
        return !isCyclic(numCourses, adj);
    }
};