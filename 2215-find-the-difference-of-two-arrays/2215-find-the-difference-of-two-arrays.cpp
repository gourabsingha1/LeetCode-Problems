class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res1, res2;
        unordered_set<int> s1(nums1.begin(), nums1.end()), s2(nums2.begin(), nums2.end());
        for(auto& s : s1) {
            if(!s2.count(s)) res1.push_back(s);
        }
        for(auto& s : s2) {
            if(!s1.count(s)) res2.push_back(s);
        }
        return {res1, res2};
    }
};