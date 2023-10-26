// Euler's totient function

#define ll long long

class Solution {
public:
    // **** Binary Exponentiation - O(logN), O(1) ****
    ll exp(ll x, ll n, ll m) {
        ll res = 1;
        while(n) {
            if(n & 1) {
                res = (res * x) % m;
            }
            x = (x * x) % m;
            n >>= 1;
        }
        return res;
    }

    int superPow(int a, vector<int>& bArray) {
        int etf = 1140, M = 1337;
        int b = 0, ten = 1;
        for (int i = bArray.size() - 1; i >= 0; i--)
        {
            b += (bArray[i] * ten) % etf;
            ten = (ten * 10) % etf;
        }
        return exp(a, b, M);
    }
};