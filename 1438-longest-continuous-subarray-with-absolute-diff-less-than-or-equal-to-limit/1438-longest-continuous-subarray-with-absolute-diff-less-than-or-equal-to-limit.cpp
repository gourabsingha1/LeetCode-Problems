// insert elements in minDeque and maxDeque
// to keep them in order, we pop_back elements
// the front elements denote the max and min elements
// when they pass the limit, remove all elements present before j

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int res = 0;
        deque<int> minQueue, maxQueue;
        for (int i = 0, j = 0; i < nums.size(); i++)
        {
            while(minQueue.size() && nums[minQueue.back()] >= nums[i]) {
                minQueue.pop_back();
            }
            minQueue.push_back(i);
            while(maxQueue.size() && nums[maxQueue.back()] <= nums[i]) {
                maxQueue.pop_back();
            }
            maxQueue.push_back(i);

            int mn = nums[minQueue.front()], mx = nums[maxQueue.front()];
            if(mx - mn > limit) {
                j++;
                if(j > minQueue.front()) {
                    minQueue.pop_front();
                }
                if(j > maxQueue.front()) {
                    maxQueue.pop_front();
                }
            }
            else {
                res = max(res, i - j + 1);
            }
        }
        return res;
    }
};