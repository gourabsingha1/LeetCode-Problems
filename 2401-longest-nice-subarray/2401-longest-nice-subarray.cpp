class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int res = 0, AND = 0;
        for (int i = 0, j = 0; i < nums.size(); i++)
        {
            while(AND & nums[i]) {
                AND ^= nums[j++];
            }
            AND |= nums[i];
            int size = i - j + 1;
            res = max(res, size);
        }
        return res;
    }
};