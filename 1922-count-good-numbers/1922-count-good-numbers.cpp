#define ll long long int
ll M = 1e9+7;
class Solution {
public:
    ll Pow(ll x, ll n, ll m = M){
        ll res = 1;
        while(n){
            if(n & 1) res = (res * x) % m;
            x = (x * x) % m;
            n >>= 1;
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        return (Pow(5, (n+1)/2)*Pow(4, n/2)) % M;
    }
};