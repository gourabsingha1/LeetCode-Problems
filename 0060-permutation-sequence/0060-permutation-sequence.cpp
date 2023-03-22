class Solution {
public:
    void nextPermutation(string& nums) {
        int i = nums.size() - 1, j = i;
        while(i - 1 >= 0 && nums[i - 1] >= nums[i]) i--;
        i--;
        if(i >= 0) {
            while(nums[i] >= nums[j]) j--;
            swap(nums[i], nums[j]);
        }
        sort(nums.begin() + i + 1, nums.end());
    }
    string getPermutation(int n, int k) {
        string num;
        for (int i = 1; i <= n; i++)
        {
            num += '0' + i;
        }
        while(--k) {
            nextPermutation(num);
        }
        return num;
    }
};