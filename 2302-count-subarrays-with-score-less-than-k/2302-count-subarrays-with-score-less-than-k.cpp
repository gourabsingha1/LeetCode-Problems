class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int j = 0, n = nums.size(), size = 0;
        long long res = 0, sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            size++;
            while(j < i && sum*size >= k){
                sum -= nums[j++];
                size--;
            }
            if(sum*size < k){
                res += size;
            }
        }
        return res;
    }
};