// classic sliding window
// when no of pairs >= k, we can find no of subsets which include
// the subset from j to i in O(1) i.e n - i

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long res = 0, n = nums.size(), pairs = 0;
        unordered_map<int, long long> mp;
        for (int i = 0, j = 0; i < n; i++)
        {
            pairs += mp[nums[i]]++;
            while(pairs >= k) {
                res += (n - i);
                pairs -= --mp[nums[j++]];
            }
        }
        return res;
    }
};