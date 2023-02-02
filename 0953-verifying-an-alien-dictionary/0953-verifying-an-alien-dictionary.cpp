class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int n = words.size(), m[26];
        for (int i = 0; i < 26; i++) m[order[i] - 'a'] = i;
        for (int i = 1; i < n; i++)
        {
            int x = words[i - 1].size(), y = words[i].size(), sz = min(x, y);
            for (int j = 0; j < sz; j++)
            {
                if(m[words[i - 1][j] - 'a'] < m[words[i][j] - 'a']){
                    break;
                }
                else if(m[words[i - 1][j] - 'a'] > m[words[i][j] - 'a'] || x > y && j + 1 == sz){
                    return 0;
                }
            }
        }
        return 1;
    }
};