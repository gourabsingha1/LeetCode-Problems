// total pairs = bad pairs + good pairs
// bad pairs = total pairs - good pairs
// good pair condition: j - i == nums[j] - nums[i]
// nums[i] - i == nums[j] - j

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size(), total = n * (n - 1) / 2, good = 0;
        unordered_map<int, long long> mp;
        for(int i = 0; i < n; i++) {
            mp[nums[i] - i]++;
        }
        for(auto& [x, freq] : mp) {
            good += freq * (freq - 1) / 2;
        }
        return total - good;
    }
};