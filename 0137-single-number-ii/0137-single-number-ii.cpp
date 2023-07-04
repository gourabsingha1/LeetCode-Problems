// Check for every bit. if the sum of all elements' setbits is divisible by 3
// if not, add that bit to result and slowly form the answer

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < 32; i++)
        {
            int mask = 1 << i, cnt = 0;
            for (int j = 0; j < nums.size(); j++)
            {
                if(nums[j] & mask) {
                    cnt++;
                }
            }
            if(cnt % 3) {
                res |= mask;
            }
        }
        return res;
    }
};