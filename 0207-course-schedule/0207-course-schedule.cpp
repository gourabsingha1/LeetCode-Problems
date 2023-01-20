class Solution {
public:
    bool isCyclic(int n, vector<vector<int>> &adj){
        int cnt = 0;
        vector<int> indegree(n, 0); // indegree = no. of arrows directed towards
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            for(auto &it : adj[i]){
                indegree[it]++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int i = q.front();
            q.pop();
            for(auto &it : adj[i]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
            cnt++;
        }
        return cnt != n;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (int i = 0; i < prerequisites.size(); i++)
        {
            int u = prerequisites[i][0], v = prerequisites[i][1];
            adj[u].push_back(v);
        }
        return !isCyclic(numCourses, adj);
    }
};