class Solution {
public:
    // **** Monotonic Stack (Strictly) - O(N), O(N) ****
    vector<int> nextGreaterElementIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        stack<int> decStack;
        for (int i = 0; i < n; i++)
        {
            while(decStack.size() && nums[decStack.top()] < nums[i]){
                res[decStack.top()] = i - decStack.top();
                decStack.pop();
            }
            decStack.push(i);
        }
        return res;
    }
    
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        return nextGreaterElementIndex(temperatures);
    }
};