class Solution {
public:
    int exp(long x, int n, int m){
        long res = 1;
        while(n){
            if(n & 1) res = (res * x) % m;
            x = (x * x) % m;
            n >>= 1;
        }
        return res;
    }
    int numSubseq(vector<int>& nums, int target) {
        int M = 1e9 + 7, n = nums.size(), res = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            int ub = upper_bound(nums.begin(), nums.end(), target - nums[i]) - nums.begin();
            int N = (ub - i);
            if(N < 1) break;
            res = (res + exp(2, N - 1, M)) % M;
        }
        return res;
    }
};