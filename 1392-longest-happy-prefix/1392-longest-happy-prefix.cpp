#define ll long long int
ll M = 1e9 + 7;
class Solution {
public:
    string longestPrefix(string s) {
        ll n = s.size(), j = n, pre = 0, suf = 0, mul = 1;
        for (int i = 0; i < n-1; i++)
        {
            pre = ((26*pre) + s[i] - 'a') % M;
            suf = (mul*(s[n - 1 - i] - 'a') + suf) % M;
            mul = (mul*26) % M;

            if(pre == suf){
                j = n - 1 - i;
            }
        }
        return s.substr(j);
    }
};