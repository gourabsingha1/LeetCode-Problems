class Solution {
public:
    bool isPal(int i, int j, string& s) {
        while(i < j) {
            if(s[i++] != s[j--]) {
                return 0;
            }
        }
        return 1;
    }
    
    int countSubstrings(string s) {
        int res = 0, n = s.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                res += isPal(i, j, s);
            }
        }
        return res;
    }
};