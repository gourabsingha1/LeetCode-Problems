class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int res = INT_MAX;
        set<int> st;
        for (int i = x; i < nums.size(); i++)
        {
            st.insert(nums[i - x]);
            auto ub = st.upper_bound(nums[i]);
            if(ub != st.end()) {
                res = min(res, abs(nums[i] - *ub));
            }
            if(ub != st.begin()) {
                res = min(res, abs(nums[i] - *prev(ub)));
            }
        }
        return res;
    }
};