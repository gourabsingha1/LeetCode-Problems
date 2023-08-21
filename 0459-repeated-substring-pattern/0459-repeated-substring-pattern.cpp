// take every substring beginning from 0 and match
// if n is not divisible by its size, then it wont match

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for (int i = 0; i < n / 2; i++)
        {
            if(n % (i + 1)) continue;
            string p = s.substr(0, i + 1);
            int j = i + 1;
            while(j < n) {
                if(s.substr(j, p.size()) != p) {
                    break;
                }
                j += p.size();
            }
            if(j == n) {
                return 1;
            }
        }
        return 0;
    }
};