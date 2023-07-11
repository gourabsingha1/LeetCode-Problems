class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int res = 0, n = s.size(), cur = 0;
        for (int i = 0, j = 0; i < n; i++)
        {
            cur += abs(s[i] - t[i]);
            while(cur > maxCost) {
                cur -= abs(s[j] - t[j++]);
            }
            res = max(res, i - j + 1);
        }
        return res;
    }
};