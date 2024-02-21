// AND is always 0 if log2(left) != log2(right)

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(!left || !right) {
            return 0;
        }
        
        int l = log2(left), r = log2(right);
        if(l == r){
            int res = left;
            for (long i = left; i <= right; i++)
            {
                res &= i;
            }
            return res;
        }
        return 0;
    }
};