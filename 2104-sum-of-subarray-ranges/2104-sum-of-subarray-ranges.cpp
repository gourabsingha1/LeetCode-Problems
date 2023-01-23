class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long n = nums.size(), res = 0, M = 1e9 + 7;
        stack<int> minStackPrev, minStackNext;
        vector<int> left(n), right(n);
        for (int i = 0; i < n; i++)
        {
            while(minStackPrev.size() && nums[minStackPrev.top()] > nums[i]){
                minStackPrev.pop();
            }
            if(minStackPrev.size()) left[i] = i - minStackPrev.top();
            else left[i] = i + 1;
            minStackPrev.push(i);

            int j = n - 1 - i;
            while(minStackNext.size() && nums[minStackNext.top()] >= nums[j]){
                minStackNext.pop();
            }
            if(minStackNext.size()) right[j] = minStackNext.top() - j;
            else right[j] = i + 1;
            minStackNext.push(j);
        }
        stack<int> maxStackPrev, maxStackNext;
        vector<int> left2(n), right2(n);
        for (int i = 0; i < n; i++)
        {
            while(maxStackPrev.size() && nums[maxStackPrev.top()] < nums[i]){
                maxStackPrev.pop();
            }
            if(maxStackPrev.size()) left2[i] = i - maxStackPrev.top();
            else left2[i] = i + 1;
            maxStackPrev.push(i);

            int j = n - 1 - i;
            while(maxStackNext.size() && nums[maxStackNext.top()] <= nums[j]){
                maxStackNext.pop();
            }
            if(maxStackNext.size()) right2[j] = maxStackNext.top() - j;
            else right2[j] = i + 1;
            maxStackNext.push(j);
        }

        for (int i = 0; i < n; i++)
        {
            res += (1LL * left2[i] * right2[i] - 1LL * left[i] * right[i]) * nums[i];
        }
        return res;
    }
};