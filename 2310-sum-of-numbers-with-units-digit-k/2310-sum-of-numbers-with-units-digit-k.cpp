class Solution {
public:
    int minimumNumbers(int num, int k) {
        if(!num){
            return 0;
        }
        else if(!k && num%10){
            return -1;
        }
        
        int K = k, Num = num, res = 0;
        while(k <= num){
            res++;
            if(k == num%10){
                return res;
            }
            num -= k;
            if(num <= 0){
                num = Num;
                k += K;
                res = 0;
            }
        }
        return -1;
    }
};