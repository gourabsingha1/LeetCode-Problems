class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        int mx = 0, res = 0;
        for(auto& x : nums) {
            mx = max(mx, ++mp[x]);
        }
        for(auto& [x, y] : mp) {
            if(y == mx) {
                res += mx;
            }
        }
        return res;
    }
};