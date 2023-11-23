// j pointer to track sorted 0's
// i - j swaps required to swap ith 0 with jth 1

class Solution {
public:
    long long minimumSteps(string s) {
        long long res = 0;
        for (int i = 0, j = 0; i < s.size(); i++)
        {
            if(s[i] == '0') {
                res += i - j++;
            }
        }
        return res;
    }
};