class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size(), pre = 0, res = 0, cnt = 0;
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            pre += nums[i];
            int x = pre % k;
            if(x < 0){
                x += k;
            }
            if(pre % k == 0){
                res++;
            }
            res += m[x]++;
        }
        return res;
    }
};