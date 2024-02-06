// res *= permutations of a multiset (word)
// ifact is used to handle the case where the number of repeating characters is large

static const int MAX_N = 1e5 + 1, M = 1e9 + 7;
int fact[MAX_N], ifact[MAX_N];

class Solution {
public:
    int exp(int a, int b) {
        int res = 1;
        while(b > 0) {
            if(b & 1) {
                res = (1LL * res * a) % M;
            }
            a = (1LL * a * a) % M;
            b >>= 1;
        }
        return res;
    }
    
    int mod_inv(int a, int m = M) {
        return exp(a, m - 2);
    }
        
    void fact_init() {
        fact[0] = fact[1] = ifact[0] = ifact[1] = 1;
        for (int i = 2; i < MAX_N; i++) {
            fact[i] = (1LL * fact[i - 1] * i) % M;
            ifact[i] = mod_inv(fact[i]);
        }
    }
    
    // to reduce time
    Solution() {
        if(fact[0] == 0) {
            fact_init();
        }
    }
    
    int countAnagrams(string s) {
        int res = 1, n = s.size();
        for (int i = 0; i < n; i++)
        {
            vector<int> freq(26, 0);
            int size = 0;
            while(i < n && s[i] != ' ') {
                freq[s[i++] - 'a']++;
                size++;
            }
            res = (1LL * res * fact[size]) % M;
            for(auto& x : freq) {
                res = (1LL * res * ifact[x]) % M;
            }
        }
        return res;
    }
};