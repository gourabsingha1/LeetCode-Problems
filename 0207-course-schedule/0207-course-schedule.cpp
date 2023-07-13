// **** Cycle Detection in Directed Graph using BFS ****
// Topological sort must not generate
class CycleDirectedBFS{
public:
    bool isCyclic(int n, vector<vector<int>> &adj){
        int cnt = 0;
        vector<int> indegree(n, 0); // indegree = no. of arrows directed towards
        queue<int> q;
        for (int u = 0; u < n; u++)
        {
            for(auto &v : adj[u]){
                indegree[v]++;
            }
        }
        for (int u = 0; u < n; u++)
        {
            if(indegree[u] == 0){
                q.push(u);
            }
        }
        while(q.size()){
            int u = q.front();
            q.pop();
            for(auto &v : adj[u]){
                indegree[v]--;
                if(indegree[v] == 0){
                    q.push(v);
                }
            }
            cnt++;
        }
        return cnt != n;
    }
};

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (int i = 0; i < prerequisites.size(); i++)
        {
            int u = prerequisites[i][0], v = prerequisites[i][1];
            adj[u].push_back(v);
        }
        
        CycleDirectedBFS CDB;
        bool res = !CDB.isCyclic(numCourses, adj);
        return res;
    }
};