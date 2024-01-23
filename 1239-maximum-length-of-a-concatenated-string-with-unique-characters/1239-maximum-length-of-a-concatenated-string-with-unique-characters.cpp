// dp + bit mask
// take only if none of the characters were taken before

class Solution {
public:
    map<pair<int, int>, int> dp;
        
    int helper(int n, int seen, vector<string>& arr) {
        if(n < 0) {
            return __builtin_popcount(seen);
        }
        if(dp.find({n, seen}) != dp.end()) {
            return dp[{n, seen}];
        }

        int temp = seen;
        for(auto& ch : arr[n]) {
            int mask = 1 << (ch - 'a');
            if(!(seen & mask)) {
                seen |= mask;
            }
            else {
                seen = temp;
                break;
            }
        }
        int take = helper(n - 1, seen, arr);
        int notTake = helper(n - 1, temp, arr);
        return dp[{n, seen}] = max(take, notTake);
    }

    int maxLength(vector<string>& arr) {
        return helper(arr.size() - 1, 0, arr);
    }
};