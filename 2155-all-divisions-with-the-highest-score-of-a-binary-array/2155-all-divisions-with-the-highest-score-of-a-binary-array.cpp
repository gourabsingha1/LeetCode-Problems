class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        vector<int> res = {0};
        int n = nums.size(), left = 0, right = accumulate(nums.begin(), nums.end(), 0), maxScore = right;
        for (int i = 0; i < n; i++)
        {
            left += (nums[i] == 0);
            right -= (nums[i] == 1);
            int curScore = left + right;
            if(maxScore < curScore) {
                maxScore = curScore;
                res.clear();
            }
            if(maxScore == curScore) {
                res.push_back(i + 1);
            }
        }
        return res;
    }
};