// for a bar i, we can extend its width only if
// the neighbours heights >= heights[i]
// other way to find the last neighbour is using NSE and PSE

class Solution {
public:
    vector<int> nextSmallerElementIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, n); // out of bound = n
        stack<int> incStack;
        for (int i = 0; i < n; i++)
        {
            while(incStack.size() && nums[incStack.top()] > nums[i]){
                res[incStack.top()] = i;
                incStack.pop();
            }
            incStack.push(i);
        }
        return res;
    }

    vector<int> prevSmallerElementIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1); // out of bound = -1
        stack<int> incStack;
        for (int i = 0; i < n; i++)
        {
            while(incStack.size() && nums[incStack.top()] >= nums[i]){
                incStack.pop();
            }
            if(incStack.size()) {
                res[i] = incStack.top();
            }
            incStack.push(i);
        }
        return res;
    }

    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        vector<int> next = nextSmallerElementIndex(heights);
        vector<int> prev = prevSmallerElementIndex(heights);
        for (int i = 0, j = 0; i < heights.size(); i++)
        {
            int width = next[i] - prev[i] - 1;
            res = max(res, heights[i] * width);
        }
        return res;
    }
};