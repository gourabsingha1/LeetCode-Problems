// for every root, find its two factors from in arr
// no. of ways to arrange them = findFactor(left) * findFactor(right)

class Solution {
public:
    int M = 1e9 + 7;
    unordered_map<int, int> dp;
    
    int factorCount(int root, unordered_map<int, bool>& mp) {
        if(dp[root]) {
            return dp[root];
        }
        
        int res = 1;
        for(auto& [left, y] : mp) {
            int right = root / left;
            if(root % left == 0 && mp.find(right) != mp.end()) {
                res = (res + 1LL * factorCount(left, mp) * factorCount(right, mp)) % M;
            }
        }
        return dp[root] = res;
    }

    int numFactoredBinaryTrees(vector<int>& arr) {
        int res = 0;
        unordered_map<int, bool> mp;
        for(auto& root : arr) {
            mp[root] = 1;
        }
        for(auto& root : arr) {
            res = (res + factorCount(root, mp)) % M;
        }
        return res;
    }
};