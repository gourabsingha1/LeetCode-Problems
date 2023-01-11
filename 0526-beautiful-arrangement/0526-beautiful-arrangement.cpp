class Solution {
public:
    void helper2(int currInd, vector<int>& nums, int &res){
        int n = nums.size();
        if(currInd == n){
            res++;
            return;
        }
        for (int i = currInd; i < n; i++)
        {
            if(nums[i] % (currInd + 1) && (currInd + 1) % nums[i]) continue;
            swap(nums[i], nums[currInd]);
            helper2(currInd + 1, nums, res);
            swap(nums[i], nums[currInd]);
        }
    }
    int countArrangement(int n) {
        int res = 0;
        vector<int> nums;
        for (int i = 1; i <= n; i++)
        {
            nums.push_back(i);
        }
        helper2(0, nums, res);
        return res;
    }
};