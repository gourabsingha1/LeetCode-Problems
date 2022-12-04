class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int i = 0;
        for ( ; i < nums.size(); i++) pq.push(nums[i]);
        i = 0;
        while(pq.size()){
            nums[i++] = pq.top();
            pq.pop();
        }
        return nums;
    }
};