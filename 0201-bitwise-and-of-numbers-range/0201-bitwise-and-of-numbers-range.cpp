class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(!left || !right) return 0;
        int res = left, l = log2(left), r = log2(right);
        if(l == r){
            for (long i = left; i <= right; i++)
            {
                res &= i;
            }
            return res;
        }
        return 0;
    }
};