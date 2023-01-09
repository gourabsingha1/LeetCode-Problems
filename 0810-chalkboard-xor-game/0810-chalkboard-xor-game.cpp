class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int res = 0;
        for(auto &x : nums) res ^= x;
        return !res || nums.size() % 2 == 0;
    }
};
