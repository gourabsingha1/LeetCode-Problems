class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int,int> mp;
        for (auto &x : nums1) mp[x]++;
        for (auto &x : nums2)
            if(mp[x]){
                res.push_back(x);
                mp[x]--;
            }
        return res;
    }
};