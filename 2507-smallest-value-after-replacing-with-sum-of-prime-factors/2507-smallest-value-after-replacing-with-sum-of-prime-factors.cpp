class Solution {
public:
    bool isPrime(int n){
        if(n <= 1) return 0;
        for (int i = 2; i <= sqrt(n); i++)
        {
            if(n%i == 0){
                return 0;
            }
        }
        return 1;
    }
    int smallestValue(int n) {
        if(n == 4) return n;
        while(!isPrime(n)){
            int i = 2, sum = 0;
            while(n > 1){
                if(n%i == 0){
                    n /= i;
                    sum += i;
                }
                else i++;
            }
            n = sum;
        }
        return n;
    }
};