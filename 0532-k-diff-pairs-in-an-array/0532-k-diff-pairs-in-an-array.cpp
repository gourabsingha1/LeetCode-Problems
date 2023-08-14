class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        unordered_set<int> st;
        for (int i = 0; i < n; i++)
        {
            int j = lower_bound(nums.begin(), nums.end(), nums[i] + k) - nums.begin();
            if(j < n && i != j && nums[i] + k == nums[j]) {
                st.insert(nums[j]);
            }
        }
        return st.size();
    }
};