class Solution {
public:
    int totalMoney(int n) {
        int res = 0, money = 1, extra = 0;
        for(int d = 1; d <= n; d++) {
            res += money++ + extra;
            if(d % 7 == 0) {
                extra++, money = 1;
            }
        }
        return res;
    }
};