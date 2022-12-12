class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ma = 1, mi = 1, res = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            if(!nums[i]) ma = 1, mi = 1;
            int dma = ma;
            ma = max({ma*nums[i], mi*nums[i], nums[i]});
            mi = min({dma*nums[i], mi*nums[i], nums[i]});
            res = max(res, ma);
        }
        return res;
    }
};