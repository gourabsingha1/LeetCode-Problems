class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(), res = 0, curr = 0;
        vector<int> nums;
        for (int i = n - k; i < n; i++)
        {
            nums.push_back(cardPoints[i]);
        }
        for (int i = 0; i < k; i++)
        {
            nums.push_back(cardPoints[i]);
        }
        for (int i = 0, j = 0; i < nums.size(); i++)
        {
            curr += nums[i];
            if(i >= k){
                curr -= nums[j++];
            }
            res = max(res, curr);
        }
        return res;
    }
};