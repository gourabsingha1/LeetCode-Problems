// only way to understand this is by doing dry run

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), res = 0, l = 0, r = n - 1;
        int leftBoundary = 0, rightBoundary = 0;
        while(l < r) {
            leftBoundary = max(leftBoundary, height[l]);
            rightBoundary = max(rightBoundary, height[r]);
            if(leftBoundary < rightBoundary) {
                res += (leftBoundary - height[l]);
                l++;
            }
            else {
                res += (rightBoundary - height[r]);
                r--;
            }
        }
        return res;
    }
};