class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int j = 0;
        long long res = 0, sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++;
            sum += nums[i];
            while(i-j+1 > k || m[nums[i]] == 2){
                m[nums[j]]--;
                sum -= nums[j++];
            }
            if(i-j+1 == k){
                res = max(res, sum);
            }
        }
        return res;
    }
};