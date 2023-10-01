class Solution {
public:
    string reverseWords(string s) {
        string res;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            string cur;
            while(i < n && s[i] != ' ') {
                cur += s[i++];
            }
            reverse(cur.begin(), cur.end());
            res += cur + " ";
        }
        res.pop_back();
        return res;
    }
};