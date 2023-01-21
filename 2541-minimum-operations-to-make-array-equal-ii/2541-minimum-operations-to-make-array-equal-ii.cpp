class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        if(!k){
            if(nums1 == nums2) return 0;
            else return -1;
        }
        long long res = 0, sum = 0;
        for (int i = 0; i < nums1.size(); i++)
        {
            int diff = nums1[i] - nums2[i];
            sum += diff;
            if(diff % k){
                return -1;
            }
            if(diff > 0) res += diff / k;
        }
        if(sum) return -1;
        return res;
    }
};