class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size(), res = 0;
        vector<int> v(32, 0);
        for (int i = 0; i < 32; i++)
        {
            int cnt = 0;
            for (int j = 0; j < n; j++)
            {
                cnt += (nums[j] >> i) & 1;
            }
            res += (n - cnt) * cnt;
        }
        return res;
    }
};