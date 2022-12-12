class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> m, mp;
        for (int i = 0; i < s.size(); i++)
        {
            if(m[s[i]] != NULL && m[s[i]] != t[i] || mp[t[i]] != NULL && mp[t[i]] != s[i]){
                return 0;
            }
            m[s[i]] = t[i], mp[t[i]] = s[i];
        }
        return 1;
    }
};