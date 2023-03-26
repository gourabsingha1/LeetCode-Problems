#define ll long long int
class Solution {
public:
    unordered_map<ll, bool> sieveIsPrime;
    void Sieve(ll n) {
        vector<bool> seen(n + 1);
        for (ll i = 2; i <= n; i++) {
            if(!seen[i]) {
                sieveIsPrime[i] = 1;
            }
            for (ll j = i * i; j <= n; j += i) {
                seen[j] = 1;
            }
        }
    }
    bool primeSubOperation(vector<int>& nums) {
        Sieve(1000);
        int prev = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int p = nums[i];
            while(p) {
                if(sieveIsPrime[p] && prev < nums[i] - p) {
                    break;
                }
                p--;
            }
            if(!p && !sieveIsPrime[p] && prev >= nums[i]) {
                return 0;
            }
            prev = nums[i] - p;
        }
        return 1;
    }
};