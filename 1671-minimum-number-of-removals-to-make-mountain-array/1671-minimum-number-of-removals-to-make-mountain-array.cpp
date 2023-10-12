// for an index, check longest increasing subsequence till that index
// and check longest decreasing subsequence from that index
// use prefix and suffix array to check in O(1)
// res = n - (maximum length of LIS + LDS - 1) (-1 because we are counting the current index twice)

class Solution {
public:
    vector<int> lengthOfLis(vector<int>& nums) {
        vector<int> LIS = {nums[0]}, res(nums.size());
        res[0] = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            int lb = lower_bound(LIS.begin(), LIS.end(), nums[i]) - LIS.begin();
            if(lb == LIS.size()) {
                LIS.push_back(nums[i]);
            }
            else {
                LIS[lb] = nums[i];
            }
            res[i] = LIS.size();
        }
        return res;
    }

    int minimumMountainRemovals(vector<int>& nums) {
        int res = 0, n = nums.size();
        vector<int> LIS = lengthOfLis(nums);
        reverse(nums.begin(), nums.end()); // to find LDS
        vector<int> LDS = lengthOfLis(nums); // LDS in reverse order
        reverse(LDS.begin(), LDS.end()); // correct LDS order
        for (int i = 1; i < n; i++)
        {
            if(LIS[i] >= 2 && LDS[i] >= 2) { // checks the condition of mountain array
                res = max(res, LIS[i] + LDS[i] - 1);
            }
        }
        return n - res;
    }
};