class Solution {
public:
    bool res = 0;
    void dfs(int i, int n, vector<int> &arr, vector<bool> &vis){
        if(i < 0 || i >= n || vis[i] == 1) return;
        if(arr[i] == 0){
            res = 1;
            return;
        }
        vis[i] = 1;
        dfs(i + arr[i], n, arr, vis);
        dfs(i - arr[i], n, arr, vis);
    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> vis(n, 0);
        dfs(start, n, arr, vis);
        return res;
    }
};