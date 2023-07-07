class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int res = 0, cnt1 = 0, cnt2 = 0;
        for (int i = 0, j1 = 0, j2 = 0; i < answerKey.size(); i++)
        {
            // Replace F
            if(answerKey[i] == 'F') {
                cnt1++;
            }
            while(cnt1 > k) {
                if(answerKey[j1] == 'F') {
                    cnt1--;
                }
                j1++;
            }
            int size1 = i - j1 + 1;

            // Replace T
            if(answerKey[i] == 'T') {
                cnt2++;
            }
            while(cnt2 > k) {
                if(answerKey[j2] == 'T') {
                    cnt2--;
                }
                j2++;
            }
            int size2 = i - j2 + 1;
            res = max({res, size1, size2});
        }
        return res;
    }
};