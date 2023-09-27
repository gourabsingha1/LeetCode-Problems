// dry run on ab2cd2
//       len: 1245612
// when we travese from back and hit k == 0, we find the character

class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long i = 0, n = s.size(), len = 0;
        while(len < k)
        {
            if(isdigit(s[i])) {
                len *= s[i] - '0';
            }
            else {
                len++;
            }
            i++;
        }
        for (int j = i - 1; j >= 0; j--)
        {
            k %= len;
            if(k == 0 && !isdigit(s[j])) {
                return string(1, s[j]);
            }
            
            if(isdigit(s[j])) {
                len /= s[j] - '0';
            }
            else {
                len--;
            }
        }
        return "";
    }
};