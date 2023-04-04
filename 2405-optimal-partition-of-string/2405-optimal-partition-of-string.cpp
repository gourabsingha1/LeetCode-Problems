class Solution {
public:
    int partitionString(string s) {
        int res = 1, m[26] = {}, j = 0;
        for (int i = 0; i < s.size(); i++)
        {
            m[s[i] - 'a']++;
            if(m[s[i] - 'a'] > 1){
                res++;
                while(j < i) {
                    m[s[j++] - 'a']--;
                }
            }
        }
        return res;
    }
};