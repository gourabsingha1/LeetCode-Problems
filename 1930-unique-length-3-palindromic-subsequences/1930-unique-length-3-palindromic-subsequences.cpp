// find the first and last location of a character
// then count unique elements within the range
// for every i, if it lies bw range of chars from a to z
// then push s[i] in their respective characters set

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int res = 0, n = s.size();
        int mp[26][2] = {};
        for (int i = 0; i < n; i++)
        {
            if(mp[s[i] - 'a'][0] == 0) {
                mp[s[i] - 'a'][0] = i + 1;
            }
            mp[s[i] - 'a'][1] = i;
        }
        
        unordered_map<int, set<int>> st;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                if(mp[j][0] - 1 < i && i < mp[j][1]) {
                    st[j].insert(s[i] - 'a');
                }
            }
        }
        for(auto& [ch, mid] : st) {
            res += mid.size();
        }
        return res;
    }
};