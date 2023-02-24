class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size(), mini = INT_MAX, maxy, diff = INT_MAX;
        priority_queue<int> maxHeap;
        for (int i = 0; i < n; i++) {
            if(nums[i] % 2 == 1) nums[i] *= 2;
            mini = min(mini, nums[i]);
            maxHeap.push(nums[i]);
        }
        while (maxHeap.top() % 2 == 0) {
            maxy = maxHeap.top();
            maxHeap.pop();
            diff = min(diff, maxy - mini);
            maxy = maxy / 2;
            maxHeap.push(maxy);
            mini = min(maxy, mini);
        }
        diff = min(diff, maxHeap.top() - mini);
        return diff;
    }
};