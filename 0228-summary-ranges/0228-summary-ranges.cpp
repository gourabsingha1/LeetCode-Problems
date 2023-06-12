class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int start = nums[i], end = nums[i];
            while(i + 1 < n && 0LL + nums[i + 1] - end == 1) {
                end = nums[i + 1];
                i++;
            }
            if(start == end) {
                res.push_back(to_string(start));
            }
            else {
                res.push_back(to_string(start) + "->" + to_string(end));
            }
        }
        return res;
    }
};