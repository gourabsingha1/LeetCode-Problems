class Solution {
public:
    int getSum(int a, int b) {
        int res = 0, carry = 0;
        for (int i = 0; i < 32; i++)
        {
            if(a&(1<<i) && b&(1<<i)){
                if(carry){
                    res = res | (1<<i);
                }
                carry = 1;
            }
            else if((a&(1<<i))==0 && b&(1<<i) || a&(1<<i) && (b&(1<<i))==0){
                if(!carry){
                    res = res | (1<<i);
                }
            }
            else{
                if(carry){
                    res = res | (1<<i);
                    carry = 0;
                }
            }
        }
        return res;
    }
};