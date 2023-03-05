class Solution {
public:
    int minJumps(vector<int>& arr) {
        int res = 0, n = arr.size();
        unordered_map<int, vector<int>> adj;
        vector<bool> vis(n);
        for (int i = 0; i < n; i++)
        {
            adj[arr[i]].push_back(i);
        }
        queue<int> q;
        q.push(0), vis[0] = 1;
        while(q.size()){
            int t = q.size();
            while(t--){
                int i = q.front(), u = arr[i];
                q.pop();
                if(i == n - 1){
                    return res;
                }
                if(i + 1 < n) adj[u].push_back(i + 1);
                if(i > 0) adj[u].push_back(i - 1);
                for(int &v : adj[u]){
                    if(!vis[v]){
                        q.push(v);
                        vis[v] = 1;
                    }
                }
                adj[u].clear();
            }
            res++;
        }
        return -1;
    }
};