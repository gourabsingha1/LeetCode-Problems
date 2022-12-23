class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, n = prices.size(), pre[n], suf[n];
        pre[0] = prices[0], suf[n-1] = prices[n-1];
        for (int i = 1; i < n; i++) pre[i] = min(prices[i], pre[i-1]);
        for (int i = n-2; i >= 0; i--) suf[i] = max(prices[i], suf[i+1]);
        for (int i = 1; i < n; i++)
        {
            res = max(res, suf[i] - pre[i-1]);
        }
        return res;
    }
};