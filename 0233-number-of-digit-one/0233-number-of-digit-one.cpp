#define ll long long

class countGivenDigit {
public:
    ll dp[10][2][10];

    // cnt = count of givenDigit present in the number
    ll helper(string& s, int& givenDigit, int pos = 0, bool tight = 1, int cnt = 0) {
        if(pos == s.size()) {
            return cnt;
        }
        if(dp[pos][tight][cnt] != -1) {
            return dp[pos][tight][cnt];
        }

        ll res = 0;
        if(tight == 1) {
            for (int i = 0; i <= s[pos] - '0'; i++)
            {
                if(i == s[pos] - '0') {
                    res += helper(s, givenDigit, pos + 1, 1, cnt + (i == givenDigit));
                }
                else {
                    res += helper(s, givenDigit, pos + 1, 0, cnt + (i == givenDigit));
                }
            }
        }
        else {
            for (int i = 0; i <= 9; i++)
            {
                res += helper(s, givenDigit, pos + 1, 0, cnt + (i == givenDigit));
            }
        }
        return dp[pos][tight][cnt] = res;
    }

    ll solve(ll l, ll r, int givenDigit) {
        l--;
        string a = to_string(l), b = to_string(r);
        memset(dp, -1, sizeof(dp));
        ll res1 = helper(a, givenDigit); // from 1 to l
        memset(dp, -1, sizeof(dp));
        ll res2 = helper(b, givenDigit); // from 1 to r
        return res2 - res1;
    }
};

class Solution {
public:
    int countDigitOne(int n) {
        countGivenDigit cgd;
        return cgd.solve(1, n, 1);
    }
};