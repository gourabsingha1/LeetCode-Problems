// **** Z-Algorithm - O(N + M), O(N + M) ****
class Solution {
public:
    vector<int> zAlgo(string& s) {
        int n = s.size(), l = 0, r = 0;
        vector<int> z(n);
        for (int i = 1; i < n; i++)
        {
            if(i > r) {
                l = r = i;
                while(r < n && s[r - l] == s[r]) {
                    r++;
                }
                z[i] = r - l;
                r--;
            }
            else {
                int ind = i - l;
                if(i + z[ind] <= r) {
                    z[i] = z[ind];
                }
                else {
                    l = i;
                    while(r < n && s[r - l] == s[r]) {
                        r++;
                    }
                    z[i] = r - l;
                    r--;
                }
            }
        }
        return z;
    }

    int strStr(string& haystack, string& needle) {
        string tot = needle + "$" + haystack;
        vector<int> z = zAlgo(tot);
        for (int i = 0; i < z.size(); i++)
        {
            if(z[i] == needle.size()) {
                return i - needle.size() - 1;
            }
        }
        return -1;
    }
};