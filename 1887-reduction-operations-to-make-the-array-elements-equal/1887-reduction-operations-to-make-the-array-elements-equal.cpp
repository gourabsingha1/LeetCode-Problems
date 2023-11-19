// only way to make all elements equal is to reduce all elements to the min element
// after sorting, for every nums[i], it will require (the number of distict elements till i) - 1 operation
// to reduce down to the minimum element
// -1 to exclude the min element

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int res = 0;
        sort(nums.begin(), nums.end());
        set<int> st;
        for(auto& num : nums) {
            st.insert(num);
            res += st.size() - 1;
        }
        return res;
    }
};