class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.size(), j = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if(s[i] == '1') {
                s[i] = '0', s[j++] = '1';
            }
        }
        if(s[n - 1] == '0') {
            s[j - 1] = '0', s[n - 1] = '1';
        }
        return s;
    }
};