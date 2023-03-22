class Solution {
public:
    string getPermutation(int n, int k) {
        string num, res;
        int fact = 1;
        for (int i = 1; i <= n; i++)
        {
            num += '0' + i;
            fact *= i;
        }
        fact /= n, k--;
        while(num.size()) {
            res += num[k / fact];
            num.erase(num.begin() + k / fact);
            k %= fact;
            if(num.size()) {
                fact /= num.size();
            }
        }
        return res;
    }
};