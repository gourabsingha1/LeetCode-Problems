class Solution {
public:
    int tribonacci(int n) {
        int a = 0, b = 1, c = 1;
        if(!n){
            return 0;
        }
        else if(n < 3){
            return 1;
        }

        for (int i = 3; i <= n; i++)
        {
            int temp = a + b + c;
            a = b;
            b = c;
            c = temp;
        }
        return c;
    }
};