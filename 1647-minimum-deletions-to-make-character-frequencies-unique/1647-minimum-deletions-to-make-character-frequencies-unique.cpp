class Solution {
public:
    int minDeletions(string s) {
        int res = 0, n = s.size();
        vector<int> freq(26, 0);
        for (int i = 0; i < n; i++)
        {
            freq[s[i] - 'a']++;
        }
        sort(freq.rbegin(), freq.rend());
        int mn = freq[0];
        for (int i = 1; i < 26; i++)
        {
            mn = max(0, min(mn - 1, freq[i]));
            res += freq[i] - mn;
        }
        return res;
    }
};