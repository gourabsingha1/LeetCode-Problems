class Solution {
public:
    int countOrders(int n) {
        int res = 1, cnt = 1, M = 1e9 + 7;
        for (int i = 1; i <= n; i++, cnt += 2)
        {
            res = (1LL * res * cnt * i) % M;
        }
        return res;
    }
};