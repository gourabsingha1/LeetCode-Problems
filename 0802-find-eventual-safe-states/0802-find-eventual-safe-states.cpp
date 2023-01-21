class Solution {
public:
    vector<int> topoSort(int n, vector<vector<int>> &adj){
        vector<int> res, indegree(n, 0); // indegree = no. of arrows directed towards
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            for(auto &it : adj[i]){
                indegree[i]++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<vector<int>> graph(n);
        for (int i = 0; i < n; i++)
        {
            for(auto &it : adj[i]){
                graph[it].push_back(i);
            }
        }
        while(q.size()){
            int i = q.front();
            q.pop();
            res.push_back(i);
            int size = res.size();
            for(auto &it : graph[i]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        return topoSort(graph.size(), graph);
    }
};