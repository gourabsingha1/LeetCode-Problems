class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.size(), one = -1;
        string res(n, '0');
        res[n - 1] = '1';
        for (int i = 0; i < n; i++)
        {
            one += s[i] == '1';
        }
        while(one--) {
            res[one] = '1';
        }
        return res;
    }
};