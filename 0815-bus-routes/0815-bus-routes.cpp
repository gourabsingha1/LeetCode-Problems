class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        queue<pair<int, int>> q; // stop, bus
        unordered_map<int, vector<int>> adj;
        unordered_map<int, bool> vis, mp;
        for (int i = 0; i < routes.size(); i++)
        {
            for (int j = 0; j < routes[i].size(); j++)
            {
                adj[routes[i][j]].push_back(i);
            }
        }
        q.push({source, 0});
        while(q.size()){
            int t = q.size();
            while(t--){
                auto [stop, bus] = q.front();
                vis[stop] = 1;
                if(stop == target){
                    return bus;
                }
                q.pop();
                for(auto &it : adj[stop]){
                    if(mp[it]) continue;
                    for (int i = 0; i < routes[it].size(); i++)
                    {
                        if(!vis[routes[it][i]]){
                            q.push({routes[it][i], bus + 1});
                        }
                    }
                    mp[it] = 1;
                }
            }
        }
        return -1;
    }
};