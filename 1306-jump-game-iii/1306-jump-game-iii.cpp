class Solution {
public:
    bool dfs(int i, int n, vector<int> &arr, vector<bool> &vis){
        if(i < 0 || i >= n || vis[i] == 1) return 0;
        if(arr[i] == 0){
            return 1;
        }
        vis[i] = 1;
        return dfs(i + arr[i], n, arr, vis) || dfs(i - arr[i], n, arr, vis);
    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> vis(n, 0);
        return dfs(start, n, arr, vis);
    }
};