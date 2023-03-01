class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int res = 0, i = 0, j = 0, n = nums1.size(), m = nums2.size();
        while(i < n && j < m) {
            while(i < n && j < m && nums1[i] > nums2[j]) {
                i++;
            }
            if(i > j) j = i;
            res = max(res, j - i);
            j++;
        }
        return res;
    }
};