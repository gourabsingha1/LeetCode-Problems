// two pointer

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int w1 = 0, i = 0, w2 = 0, j = 0, n = word1.size(), m = word2.size();
        while(w1 < n && w2 < m) {
            if(word1[w1][i] == word2[w2][j]) {
                i++, j++;
                if(i == word1[w1].size()) {
                    w1++, i = 0;
                }
                if(j == word2[w2].size()) {
                    w2++, j = 0;
                }
            }
            else {
                break;
            }
        }
        return w1 == n && w2 == m;
    }
};