class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size(), pre = 0, res = 0, cnt = 0, rem;
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            pre += nums[i];
            rem = pre % k;
            if(rem < 0){
                rem += k;
            }
            if(rem == 0){
                res++;
            }
            res += m[rem];
            m[rem]++;
        }
        return res;
    }
};