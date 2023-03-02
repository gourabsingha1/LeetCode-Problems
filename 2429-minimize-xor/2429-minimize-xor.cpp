class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt = __builtin_popcount(num2), n = log2(num1) + 1, res = 0;
        for (int i = 0; i < n && cnt; i++)
        {
            if(num1 & (1 << (n - 1 - i))) {
                res ^= (1 << (n - 1 - i));
                cnt--;
            }
        }
        if(cnt) {
            int i = 0;
            while(i < n && cnt) {
                if((num1 & (1 << i)) == 0) {
                    res ^= (1 << i);
                    cnt--;
                }
                i++;
            }
            while(cnt--) {
                res += (1 << n++);
            }
        }
        return res;
    }
};