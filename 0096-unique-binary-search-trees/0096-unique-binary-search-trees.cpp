#define ll long long int
ll M = 1e11 + 7;
class Solution {
public:
    ll nCr(ll n, ll r, ll m = M){
        r = min(r, n-r);
        ll res = 1;
        for (int i = 1; i <= r; i++)
        {
            res = (res*(n-r+i) / i) % m;
        }
        return res;
    }
    int numTrees(int n) {
        return nCr(2*n, n)/(n+1);
    }
};