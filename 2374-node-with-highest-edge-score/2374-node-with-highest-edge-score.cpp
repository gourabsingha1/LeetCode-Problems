class Solution {
public:
    int edgeScore(vector<int>& edges) {
        long long n = edges.size(), ma = 0;
        vector<long long> nums(n);
        for (int i = 0; i < n; i++)
        {
            nums[edges[i]] += i;
            ma = max(ma, nums[edges[i]]);
        }
        for (int i = 0; i < n; i++)
        {
            if(nums[i] == ma){
                return i;
            }
        }
        return -1;
    }
};