class Solution {
public:
    int minJumps(vector<int>& arr) {
        int res = 0, n = arr.size();
        unordered_map<int, vector<int>> adj;
        vector<bool> vis(n, 0);
        for (int i = 0; i < n; i++)
        {
            adj[arr[i]].push_back(i);
        }
        queue<int> q;
        q.push(0), vis[0] = 1;
        while(q.size()){
            int size = q.size();
            while(size--){
                int i = q.front();
                q.pop();
                if(i == n-1){
                    return res;
                }
                if(i > 0) adj[arr[i]].push_back(i-1);
                if(i+1 < n) adj[arr[i]].push_back(i+1);
                for(int &x : adj[arr[i]]){
                    if(!vis[x]){
                        q.push(x);
                        vis[x] = 1;
                    }
                }
                adj[arr[i]].clear();
            }
            res++;
        }

        return -1;
    }
};