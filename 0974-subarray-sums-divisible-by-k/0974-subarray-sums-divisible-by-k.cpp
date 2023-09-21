class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size(), pre = 0, res = 0;
        unordered_map<int, int> freq;
        freq[0] = 1; // initial cumulative sum = 0 and that sum % k will be equal to 0 always
        for (int i = 0; i < n; i++)
        {
            pre = (pre + nums[i]) % k;
            if(pre < 0){
                pre += k;
            }
            res += freq[pre]++;
        }
        return res;
    }
};