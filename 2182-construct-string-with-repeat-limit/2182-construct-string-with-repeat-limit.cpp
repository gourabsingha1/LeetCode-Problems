class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        string res;
        int n = s.size();
        vector<int> freq(26);
        for (int i = 0; i < n; i++)
        {
            freq[s[i] - 'a']++;
        }
        int j = 24;
        for (int i = 25; i >= 0; i--)
        {
            int cnt = repeatLimit;
            while(freq[i] && cnt) {
                res += 'a' + i;
                freq[i]--, cnt--;
            }
            if(freq[i]) {
                while(j >= 0 && !freq[j] || i == j) {
                    j--;
                }
                if(j < 0) {
                    break;
                }
                
                res += 'a' + j;
                freq[j]--;
                i++;
            }
        }
        return res;
    }
};