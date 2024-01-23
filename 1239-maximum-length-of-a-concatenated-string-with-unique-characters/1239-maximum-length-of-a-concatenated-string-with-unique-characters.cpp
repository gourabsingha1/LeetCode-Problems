// brute force
// take only if none of the characters are taken before

class Solution {
public:
    int helper(int n, vector<bool> vis, vector<string>& arr) {
        if(n < 0) {
            return accumulate(vis.begin(), vis.end(), 0);
        }

        int notTake = helper(n - 1, vis, arr);
        for(auto& ch : arr[n]) {
            if(!vis[ch - 'a']) {
                vis[ch - 'a'] = 1;
            }
            else {
                return notTake;
            }
        }
        int take = helper(n - 1, vis, arr);
        return max(take, notTake);
    }

    int maxLength(vector<string>& arr) {
        vector<bool> vis(26, 0);
        return helper(arr.size() - 1, vis, arr);
    }
};