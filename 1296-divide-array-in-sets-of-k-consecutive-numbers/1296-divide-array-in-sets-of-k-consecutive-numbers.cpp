class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if(n % k) return 0;
        map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            m[nums[i]]++;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            if(!m[nums[i]]) continue;
            for (int j = 0; j < k; j++)
            {
                if(!m[nums[i] + j]--) return 0;
            }
        }
        return 1;
    }
};