// spend O(N) time on the smaller array
// spend O(logN) time on the larger array to find the element

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if(n > m) {
            return getCommon(nums2, nums1);
        }

        for (int i = 0; i < n; i++)
        {
            if(binary_search(nums2.begin(), nums2.end(), nums1[i])) {
                return nums1[i];
            }
        }
        return -1;
    }
};