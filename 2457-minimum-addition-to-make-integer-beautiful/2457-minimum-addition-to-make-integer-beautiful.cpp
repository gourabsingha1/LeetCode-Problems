class Solution {
public:
    long long makeIntegerBeautiful(long long n, int target) {
        long long res = 0, c = 0, d = 0, s, dummy = n;
        while(dummy){
            d++;
            dummy /= 10;
        }
        s = pow(10, d); // n/s = LSB digit
        while(s >= 10 && c < target){
            s /= 10;
            c += (n/s)%10;
        }
        if(c <= target && n <= (n/s)*s) return 0;
        s *= 10;
        res = s - n%s;
        return res;
    }
};