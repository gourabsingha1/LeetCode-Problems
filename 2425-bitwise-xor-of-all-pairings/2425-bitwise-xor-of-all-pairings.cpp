class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size(), res = 0;
        if(n & 1 && m & 1){
            for(auto &x : nums1) res ^= x;
            for(auto &x : nums2) res ^= x;
        }
        else if(n & 1){
            for(auto &x : nums2) res ^= x;
        }
        else if(m & 1){
            for(auto &x : nums1) res ^= x;
        }
        return res;
    }
};