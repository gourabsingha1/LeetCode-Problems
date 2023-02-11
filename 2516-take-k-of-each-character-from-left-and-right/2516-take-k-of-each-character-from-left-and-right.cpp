class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size(), j = 0, res = 0;
        int a[3] = {};
        for (int i = 0; i < n; i++)
        {
            a[s[i] - 'a']++;
        }
        if(!(a[0] >= k && a[1] >= k && a[2] >= k)){
            return -1;
        }
        for (int i = 0; i < n; i++)
        {
            a[s[i] - 'a']--;
            while(j <= i && a[s[i] - 'a'] < k){
                a[s[j++] - 'a']++;
                if(a[0] >= k && a[1] >= k && a[2] >= k){
                    break;
                }
            }
            res = max(res, i - j + 1);
        }
        res = n - res;
        return res;
    }
};