class Solution {
public:
    int trailingZeroes(int n) {
        if(!n){
            return 0;
        }
        return n/5 + trailingZeroes(n/5);
    }
};