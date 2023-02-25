class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), res = 0;
        stack<int> decStack;
        for (int i = 0; i < n; i++)
        {
            int last = -1;
            while (decStack.size() && height[decStack.top()] <= height[i]) {
                last = height[decStack.top()];
                decStack.pop();
                if(decStack.size()){
                    res += (min(height[decStack.top()], height[i]) - last) * (i - decStack.top() - 1);
                    last = height[decStack.top()];
                }
            }
            decStack.push(i);
            // cout<<res<<' ';
        }
        return res;
    }
};