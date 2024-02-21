// (a & b) <= min(a, b)
// for left = 4, right = 14
// 14 & 13 = 12
// 12 & 11 = 8
// 8 & 7 = 0
// total 3 iterations

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while(left < right) {
            right = right & (right - 1);
        }
        return right;
    }
};