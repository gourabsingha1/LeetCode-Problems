// largest rectangle in histogram
// treat every row as the base of heights

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
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), res = 0;
        vector<int> heights(m);
        for (int j = 0; j < m; j++)
        {
            heights[j] = matrix[0][j] - '0';
        }
        res = max(res, largestRectangleArea(heights));

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(matrix[i][j] - '0' == 0) {
                    heights[j] = 0;
                }
                else {
                    heights[j]++;
                }
            }
            res = max(res, largestRectangleArea(heights));
        }
        return res;
    }
};