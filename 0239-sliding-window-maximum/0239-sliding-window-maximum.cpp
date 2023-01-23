class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq;
        for (int i = 0; i < nums.size(); i++)
        {
            while(dq.size() && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i + 1 >= k){
                res.push_back(nums[dq.front()]);
                if(i - dq.front() + 1 == k){
                    dq.pop_front();
                }
            }
        }
        return res;
    }
};