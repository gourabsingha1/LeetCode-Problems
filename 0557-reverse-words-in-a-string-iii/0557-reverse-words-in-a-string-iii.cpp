class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            int j = i;
            while(i < n && s[i] != ' ') {
                i++;
            }
            reverse(s.begin() + j, s.begin() + i);
        }
        return s;
    }
};