class Solution {
public:
    int countPal(int i, int j, string& s) {
        int res = 0;
        while(i >= 0 && j < s.size() && s[i--] == s[j++]) {
            res++;
        }
        return res;
    }

    int countSubstrings(string s) {
        int res = 0, n = s.size();
        for (int i = 0; i < n; i++)
        {
            res += countPal(i, i, s); // odd length
            res += countPal(i, i + 1, s); // even length
        }
        return res;
    }
};