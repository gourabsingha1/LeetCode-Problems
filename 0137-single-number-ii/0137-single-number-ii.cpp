// Ratta material

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x1 = 0, x2 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            x2 ^= (x1 & nums[i]);
            x1 ^= nums[i];
            
            int mask = ~(x1 & x2);
            
            x1 &= mask;
            x2 &= mask;
        }
        return x1;
    }
};