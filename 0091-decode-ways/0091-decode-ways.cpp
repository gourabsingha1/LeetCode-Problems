class Solution {
public:
    // space optimized
    int numDecodings(string s) {
        int n = s.size(), dp1 = 0, dp2 = 0;
        dp1 = s[0] != '0';
        for (int i = 1; i < n; i++)
        {
            int one = 0, two = 0;
            if(s[i] != '0') {
                one = dp1;
            }
            if(i - 1 >= 0 && (s[i - 1] == '1' || s[i - 1] == '2' && s[i] <= '6')) {
                if(i - 1 == 0) {
                    two = dp1;
                }
                else {
                    two = dp2;
                }
            }
            dp2 = dp1;
            dp1 = one + two;
        }
        return dp1;
    }
};