// set smallest to largest numbers to 'I' positions
// set largest to smallest numbers to 'D' positions

class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size(), low = 0, high = n;
        vector<int> res(n + 1);
        for (int i = 0; i < n; i++)
        {
            if(s[i] == 'I') {
                res[i] = low++;
            }
            else {
                res[i] = high--;
            }
        }
        res[n] = high;
        return res;
    }
};