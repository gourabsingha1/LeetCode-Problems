class Solution {
public:
    vector<int> z_function(string& s) {
        int n = s.size(), l = 0, r = 0;
        vector<int> z(n);
        for(int i = 1; i < n; i++) {
            if(i < r) {
                z[i] = min(r - i, z[i - l]);
            }
            while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                z[i]++;
            }
            if(i + z[i] > r) {
                l = i;
                r = i + z[i];
            }
        }
        return z;
    }
    
    int minimumTimeToInitialState(string& word, int k) {
        int res = 1, n = word.size();
        auto z = z_function(word);
        while(k * res < n) {
            if(z[k * res] >= n - k * res) {
                break;
            }
            res++;
        }
        return res;
    }
};