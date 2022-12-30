#define ll long long int
ll M = 1e9+7;
class Solution {
public:
    ll Pow(ll x, ll n, ll m = M){
        if(n == 0) return 1;
        if(n%2 == 0){
            return Pow(x*x%m, n/2)%m;
        }
        else{
            return x*(Pow(x*x%m, n/2)%m)%m;
        }
    }
    int countGoodNumbers(long long n) {
        return (Pow(5, (n+1)/2)*Pow(4, n/2)) % M;
    }
};