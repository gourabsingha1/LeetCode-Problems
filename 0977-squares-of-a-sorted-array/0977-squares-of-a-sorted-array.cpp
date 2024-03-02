// find the point such that nums[r] < 0 && nums[l] >= 0
// then expand and push the smaller square first

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res;
        int n = nums.size(), l = 0, r = n - 1;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(nums[mid] < 0) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        
        while(res.size() < n) {
            if(r >= 0 && l < n) {
                if(abs(nums[r]) < nums[l]) {
                    res.push_back(nums[r] * nums[r--]);
                }
                else {
                    res.push_back(nums[l] * nums[l++]);
                }
            }
            else if(r >= 0) {
                res.push_back(nums[r] * nums[r--]);
            }
            else {
                res.push_back(nums[l] * nums[l++]);
            }
        }
        return res;
    }
};