class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return 0;
        vector<int> vs(26, 0), vt(26, 0);
        for (int i = 0; i < s.size(); i++) vs[s[i] - 'a']++;
        for (int i = 0; i < t.size(); i++) vt[t[i] - 'a']++;
        for (int i = 0; i < 26; i++){
            if(vs[i] != vt[i]) return 0;
        }
        return 1;
    }
};