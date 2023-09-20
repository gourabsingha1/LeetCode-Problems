class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), res = 0;
        vector<int> leftBoundary(n), rightBoundary(n);
        leftBoundary[0] = height[0], rightBoundary[n - 1] = height[n - 1];
        for (int i = 1; i < n; i++)
        {
            leftBoundary[i] = max(leftBoundary[i - 1], height[i]);
            rightBoundary[n - i - 1] = max(rightBoundary[n - i], height[n - i - 1]);
        }

        for (int i = 0; i < n; i++)
        {
            res += min(leftBoundary[i], rightBoundary[i]) - height[i];
        }
        return res;
    }
};