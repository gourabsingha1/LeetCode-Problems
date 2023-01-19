class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size(), pre = 0, res = 0, cnt = 0;
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            pre += nums[i];
            if(pre % k == 0){
                res++;
            }
            if(pre % k < 0){
                res += m[pre % k + k];
                m[pre % k + k]++;
            }
            else{
                res += m[pre % k];
                m[pre % k]++;
            }
        }
        return res;
    }
};