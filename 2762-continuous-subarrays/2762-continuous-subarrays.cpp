// when the diff bw max and min element of set exceeds 2
// shrink the window i.e erase nums[j] from set
// res += st.size() bc when we add a new element
// that element creates valid subarrays with all the elements in set

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long res = 0, n = nums.size();
        multiset<int> st;
        for (int i = 0, j = 0; i < n; i++)
        {
            st.insert(nums[i]);
            while(*(--st.end()) - *st.begin() > 2) {
                st.erase(st.find(nums[j++]));
            }
            res += st.size();
        }
        return res;
    }
};