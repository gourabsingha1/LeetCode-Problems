class Solution {
public:
    string getPermutation(int n, int k) {
        string num;
        for (int i = 1; i <= n; i++)
        {
            num += '0' + i;
        }
        while(--k) {
            next_permutation(num.begin(), num.end());
        }
        return num;
    }
};