class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int res = 0, n = nums1.size();
        unordered_map<int,int> m34;
        for(int &c : nums3){
            for(int &d : nums4){
                m34[c + d]++;
            }
        }

        for(int &a : nums1){
            for(int &b : nums2){
                int z = m34[-(a + b)];
                if(z){
                    res += z;
                }
            }
        }
        return res;
    }
};