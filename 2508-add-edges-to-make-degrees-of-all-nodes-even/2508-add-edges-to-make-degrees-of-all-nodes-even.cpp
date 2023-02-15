class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        unordered_set<int> adj[n + 1];
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].insert(edges[i][1]);
            adj[edges[i][1]].insert(edges[i][0]);
        }
        vector<int> odd;
        for (int i = 1; i <= n; i++)
        {
            if(adj[i].size() & 1){
                odd.push_back(i);
            }
        }
        if(odd.size() == 2){
            for (int i = 1; i <= n; i++)
            {
                if(!adj[odd[0]].count(i) && !adj[odd[1]].count(i)){
                    return 1;
                }
            }
        }
        else if(odd.size() == 4){
            for (int i = 1; i <= n; i++)
            {
                if(!adj[odd[0]].count(odd[1]) && !adj[odd[2]].count(odd[3]) || !adj[odd[0]].count(odd[2]) && !adj[odd[1]].count(odd[3]) || !adj[odd[0]].count(odd[3]) && !adj[odd[1]].count(odd[2])){
                    return 1;
                }
            }
        }
        return !odd.size();
    }
};