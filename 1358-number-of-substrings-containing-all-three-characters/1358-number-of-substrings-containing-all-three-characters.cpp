class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> m(3,0);
        int j = 0, res = 0, n = s.size();
        for (int i = 0; i < n; i++)
        {
            m[s[i]-'a']++;
            if(m[0] && m[1] && m[2]){
                res += (n-i);
                m[s[j++]-'a']--;
                m[s[i]-'a']--;
                i--;
            }
        }
        return res;
    }
};