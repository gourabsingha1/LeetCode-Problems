class Solution {
public:
    bool dfs(int i, vector<int>& arr, vector<bool>& vis){
        if(i < 0 || i >= arr.size() || vis[i]) return 0;
        if(!arr[i]){
            return 1;
        }
        vis[i] = 1;
        return dfs(i + arr[i], arr, vis) || dfs(i - arr[i], arr, vis);
    }
    bool canReach(vector<int>& arr, int start) {
        vector<bool> vis(arr.size());
        return dfs(start, arr, vis);
    }
};