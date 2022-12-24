class Solution {
public:
    int numTilings(int n) {
        if(n < 3) return n;
        
        int f1 = 1, f2 = 2, f3 = 5, M = 1e9 + 7;
        for (int i = 4; i <= n; i++)
        {
            int temp = f3;
            f3 = ((2*f3)%M + f1)%M;
            f1 = f2;
            f2 = temp;
        }
        return f3;
    }
};