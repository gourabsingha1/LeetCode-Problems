class Solution {
public:
    int minOperations(int n) {
        int res = 0;
        for (int i = 0; i < n/2; i++)
        {
            res += (2*(n-1-i)+1 - (2*i+1))/2;
        }
        return res;
    }
};