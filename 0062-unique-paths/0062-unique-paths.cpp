#define ll long long int

class Solution {
public:
    ll nCr(ll n, ll r){
        r = min(r, n-r);
        ll res = 1;
        for (int i = 1; i <= r; i++)
        {
            res = res*(n-r+i)/i;
        }
        return res;
    }
    int uniquePaths(int m, int n) {
        if(m > n) swap(n, m);
        return nCr(n+m-2, m-1);
    }
};