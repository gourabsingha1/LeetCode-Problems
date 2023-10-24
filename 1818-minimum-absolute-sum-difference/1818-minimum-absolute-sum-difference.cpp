// we want to replace nums1[i] with the lower_bound of nums2[i] or 1 less than lower_bound of nums2[i]

class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int res = INT_MAX, sum = 0, M = 1e9 + 7, n = nums1.size();
        set<int> st;
        for (int i = 0; i < n; i++)
        {
            st.insert(nums1[i]);
            sum = (sum + abs(nums1[i] - nums2[i])) % M;
        }

        for (int i = 0; i < n; i++)
        {
            int diff = abs(nums1[i] - nums2[i]);
            auto lb = st.lower_bound(nums2[i]); // must exist
            if(lb != end(st)) {
                res = min(res, sum - diff + *lb - nums2[i]);
            }
            if(lb != begin(st)) {
                res = min(res, sum - diff + abs(*prev(lb) - nums2[i]));
            }
        }
        return (res + M) % M;
    }
};