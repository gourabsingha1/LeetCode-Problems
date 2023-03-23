class Solution {
public:
    int climbStairs(int n) {
        if(n < 2) {
            return n;
        }
        int one = 1, two = 1;
        for(int i = 2; i <= n; i++){
            int temp = two;
            two += one;
            one = temp;
        }
        return two;
    }
};