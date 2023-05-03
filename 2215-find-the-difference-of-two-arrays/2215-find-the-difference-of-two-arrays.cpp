class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res1, res2;
        unordered_map<int, bool> mp1, mp2;
        for (int i = 0; i < nums1.size(); i++)
        {
            mp1[nums1[i]] = 1;
        }
        for (int i = 0; i < nums2.size(); i++)
        {
            mp2[nums2[i]] = 1;

            if(!mp1[nums2[i]]) {
                res2.push_back(nums2[i]);
                mp1[nums2[i]] = 1;
            }
        }
        for (int i = 0; i < nums1.size(); i++)
        {
            if(!mp2[nums1[i]]) {
                res1.push_back(nums1[i]);
                mp2[nums1[i]] = 1;
            }
        }
        return {res1, res2};
    }
};