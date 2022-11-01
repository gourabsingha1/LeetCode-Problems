class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int res = 0, sum = 0;
        unordered_map<int,int> m;
        int j = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++;
            while(m[nums[i]] == 2){
                m[nums[j]]--;
                sum -= nums[j];
                j++;
            }
            sum += nums[i];
            res = max(res, sum);
        }
        return res;
    }
};