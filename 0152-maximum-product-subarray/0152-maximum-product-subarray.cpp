class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ma = nums[0], mi = nums[0], res = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            int dma = ma;
            ma = max({ma*nums[i], mi*nums[i], nums[i]});
            mi = min({dma*nums[i], mi*nums[i], nums[i]});
            res = max(res, ma);
        }
        return res;
    }
};