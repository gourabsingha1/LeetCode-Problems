class Solution {
public:
    unordered_map<int, int> m;
    int findParent(int n){
        if(!m[n]){
            return 0;
        }
        else if(m[n] > 1){
            return m[n];
        }
        return m[n] = findParent(n + 1) + 1;
    }
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size(), res = 0;
        for (int i = 0; i < n; i++)
        {
            m[nums[i]] = 1;
        }
        for (int i = 0; i < n; i++)
        {
            res = max(res, findParent(nums[i]));
        }
        return res;
    }
};