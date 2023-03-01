class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int res = 0, i = 0, n = word.size();
        vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        while(i < n) {
            if(word[i] == 'a') {
                int j = i, k = 0;
                while(++i < n) {
                    if(word[i] != vowels[k]) {
                        k++;
                        if(k == 5 || k < 5 && word[i] != vowels[k]) {
                            break;
                        }
                    }
                }
                if(k == 5 || k == 4 && i == n) {
                    res = max(res, i - j);
                }
            }
            else {
                i++;
            }
        }
        return res;
    }
};