// max diff bw first and last occurrence of a character

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int res = -1;
        vector<int> mp(26, -1);
        for (int i = 0; i < s.size(); i++)
        {
            if(mp[s[i] - 'a'] == -1) {
                mp[s[i] - 'a'] = i;
            }
            else {
                res = max(res, i - mp[s[i] - 'a'] - 1);
            }
        }
        return res;
    }
};