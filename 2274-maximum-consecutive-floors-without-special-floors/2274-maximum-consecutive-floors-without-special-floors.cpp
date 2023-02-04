class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        int n = special.size(), res = 0, cnt = 0;
        sort(special.begin(), special.end());
        res = max(abs(special[0] - bottom), abs(top - special[n - 1]));
        for (int i = 1; i < n; i++)
        {
            res = max(res, special[i] - special[i - 1] - 1);
        }
        return res;
    }
};