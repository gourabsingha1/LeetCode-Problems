// brute force
// take only if none of the characters were taken before

class Solution {
public:
    map<pair<int, vector<bool>>, int> dp;
        
    int helper(int n, vector<bool> vis, vector<string>& arr) {
        if(n < 0) {
            return accumulate(vis.begin(), vis.end(), 0);
        }
        if(dp.find({n, vis}) != dp.end()) {
            return dp[{n, vis}];
        }

        int notTake = helper(n - 1, vis, arr);
        vector<bool> temp = vis;
        for(auto& ch : arr[n]) {
            if(!vis[ch - 'a']) {
                vis[ch - 'a'] = 1;
            }
            else {
                return dp[{n, temp}] = notTake;
            }
        }
        int take = helper(n - 1, vis, arr);
        return dp[{n, vis}] = max(take, notTake);
    }

    int maxLength(vector<string>& arr) {
        vector<bool> vis(26, 0);
        return helper(arr.size() - 1, vis, arr);
    }
};