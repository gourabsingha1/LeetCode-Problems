class Solution {
public:
    int numSplits(string s) {
        int n = s.size(), res = 0, leftCnt = 0, rightCnt = 0;
        vector<int> mpLeft(26, 0), mpRight(26, 0);
        for (int i = 0; i < n; i++)
        {
            int c = s[i] - 'a';
            mpRight[c]++;
            if(mpRight[c] == 1) {
                rightCnt++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            int c = s[i] - 'a';
            mpLeft[c]++, mpRight[c]--;
            if(mpLeft[c] == 1) {
                leftCnt++;
            }
            if(mpRight[c] == 0) {
                rightCnt--;
            }
            res += leftCnt == rightCnt;
        }
        return res;
    }
};