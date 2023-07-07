// make a window with the most frequent characters
// subtract extra characters
// if no of extra characters exceed k, shrink the window

class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        vector<int> mp(26, 0);
        for (int i = 0, j = 0; i < s.size(); i++)
        {
            mp[s[i] - 'A']++;
            int size = i - j + 1;
            int cnt = size - *max_element(mp.begin(), mp.end());
            while(cnt > k) {
                mp[s[j++] - 'A']--;
                size = i - j + 1;
                cnt = size - *max_element(mp.begin(), mp.end());
            }
            res = max(res, size);
        }
        return res;
    }
};