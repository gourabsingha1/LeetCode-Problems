class Solution {
public:
    bool wordPattern(string s, string t) {
        unordered_map<char, string> m;
        unordered_map<string, char> mp;
        int j = 0;
        for (int i = 0; i < s.size(); i++)
        {
            string p;
            while(j < t.size() && t[j] != ' '){
                p += t[j++];
            } j++;
            if(m[s[i]].size() && m[s[i]] != p || mp[p] != NULL && mp[p] != s[i]){
                return 0;
            }
            m[s[i]] = p, mp[p] = s[i];
        }
        return j-1 == t.size();
    }
};