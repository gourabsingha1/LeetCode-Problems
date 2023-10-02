class Solution {
public:
    int dp[500][500];
    
    int helper(int i, int cnt, int n, vector<int>& slices) {
        if(i >= n) {
            if(cnt == 0) {
                return 0;
            }
            return -1e9;
        }
        if(dp[i][cnt] != -1) {
            return dp[i][cnt];
        }

        int take = 0;
        if(cnt) {
            take = slices[i] + helper(i + 2, cnt - 3, n, slices);
        }
        int notTake = helper(i + 1, cnt, n, slices);
        return dp[i][cnt] = max(take, notTake);
    }

    int maxSizeSlices(vector<int>& slices) {
        memset(dp, -1, sizeof(dp));
        int res1 = helper(0, slices.size(), slices.size() - 1, slices);
        memset(dp, -1, sizeof(dp));
        int res2 = helper(1, slices.size(), slices.size(), slices);
        return max(res1, res2);
    }
};