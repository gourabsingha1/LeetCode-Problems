class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size(), res = 0;
        vector<int> v(32, 0);
        for(auto &x : nums){
            for (int i = 0; i < 32; i++)
            {
                v[i] += (x & (1<<i)) != 0;
            }
        }
        for (int i = 0; i < 32; i++)
        {
            res += (n - v[i]) * v[i];
        }
        return res;
    }
};