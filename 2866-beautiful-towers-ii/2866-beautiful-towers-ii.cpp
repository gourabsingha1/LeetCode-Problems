// curLeft[i] stores the sum of left part of mountains till i
// from i till prevSmallerElementIndex[i] (lInd), the sum of heights of mountains will be
// maxHeights[i] * (i - lInd);
// finally, curLeft[i] = curLeft[lInd] + maxHeights[i] * (i - lInd); if lInd exists

#define ll long long

class Solution {
public:
    vector<int> prevSmallerElementIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> incStack;
        for (int i = 0; i < n; i++)
        {
            while(incStack.size() && nums[incStack.top()] > nums[i]){
                incStack.pop();
            }
            if(incStack.size()) {
                res[i] = incStack.top();
            }
            incStack.push(i);
        }
        return res;
    }
    
    vector<int> nextSmallerElementIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> incStack;
        for (int i = 0; i < n; i++)
        {
            while(incStack.size() && nums[incStack.top()] >= nums[i]){
                res[incStack.top()] = i;
                incStack.pop();
            }
            incStack.push(i);
        }
        return res;
    }
    
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        ll res = 0, l = 0, r = 0, n = maxHeights.size();
        auto left = prevSmallerElementIndex(maxHeights);
        auto right = nextSmallerElementIndex(maxHeights);
        vector<ll> curLeft(n), curRight(n);
        
        for (int i = 0; i < n; i++)
        {
            ll lInd = left[i], l = 0;
            if(lInd != -1) {
                l = curLeft[lInd] + maxHeights[i] * (i - lInd);
            }
            else {
                l = 1LL * maxHeights[i] * (i + 1);
            }
            curLeft[i] = l;
        }

        for (int i = n - 1; i >= 0; i--)
        {
            ll rInd = right[i], r = 0;
            if(rInd != -1) {
                r = curRight[rInd] + maxHeights[i] * (rInd - i);
            }
            else {
                r = 1LL * maxHeights[i] * (n - i);
            }
            curRight[i] = r;
        }
        
        for (int i = 0; i < n; i++)
        {
            res = max(res, curLeft[i] + curRight[i] - maxHeights[i]);
        }
        return res;
    }
};