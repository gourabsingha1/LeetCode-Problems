class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int i = k, j = k, n = nums.size(), res = nums[k], mn = res;
        while(i >= 0 && j < n) {
            mn = min({mn, nums[i], nums[j]});
            res = max(res, mn * (j - i + 1));
            
            // edge cases
            if(j + 1 == n && i > 0) {
                i--;
            }
            else if(i == 0 && j + 1 < n) {
                j++;
            }
            else if(i > 0 && j + 1 < n) {
                if(nums[j + 1] > nums[i - 1]) {
                    j++;
                }
                else {
                    i--;
                }
            }
            else {
                break;
            }
        }
        return res;
    }
};
