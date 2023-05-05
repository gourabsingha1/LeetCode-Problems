class Solution {
public:
    bool isVowel(char& ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    int maxVowels(string s, int k) {
        int res = 0, cur = 0, j = 0;
        for (int i = 0; i < s.size(); i++)
        {
            cur += isVowel(s[i]);
            if(i >= k) {
                cur -= isVowel(s[j++]);
            }
            res = max(res, cur);
        }
        return res;
    }
};