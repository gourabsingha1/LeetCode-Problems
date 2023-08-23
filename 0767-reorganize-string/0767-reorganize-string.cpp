// alternate placing the most common letters

class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size(), mx = 0;
        char mxChar = 0;
        string res = s;
        vector<int> freq(26);
        for (int i = 0; i < n; i++)
        {
            int x = s[i] - 'a';
            if(mx < ++freq[x]) {
                mx = freq[x];
                mxChar = s[i];
            }
        }
        if(mx > (n + 1) / 2) {
            return "";
        }

        int ind = 0;
        while(freq[mxChar - 'a']) {
            res[ind] = mxChar;
            ind += 2, freq[mxChar - 'a']--;
        }
        for (int i = 0; i < 26; i++)
        {
            while(freq[i]) {
                if(ind >= n) {
                    ind = 1;
                }
                res[ind] = 'a' + i;
                ind += 2, freq[i]--;
            }
        }
        return res;
    }
};