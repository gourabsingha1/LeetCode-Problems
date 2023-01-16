class Solution {
public:
    int partitionString(string s) {
        int res = 0, m[26] = {}, last = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if(m[s[i] - 'a'] >= last){
                res++;
                last = i + 1;
            }
            m[s[i] - 'a'] = i + 1;
        }
        return res;
    }
};