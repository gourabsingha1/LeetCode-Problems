class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), res = 0;
        stack<int> minStack;
        for (int r = 0; r < n; r++)
        {
            int rightBoundary = height[r];
            while(minStack.size() && height[minStack.top()] <= rightBoundary) {
                int mid = height[minStack.top()];
                minStack.pop();
                if(minStack.size()) {
                    int l = minStack.top(), leftBoundary = height[l];
                    res += (min(leftBoundary, rightBoundary) - mid) * (r - l - 1);
                }
            }
            minStack.push(r);
        }
        return res;
    }
};