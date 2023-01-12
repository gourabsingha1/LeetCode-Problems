class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ma = *max_element(nums.begin(), nums.end()), res = 0, cnt = 0;
        for(auto &x : nums){
            if(x == ma){
                cnt++;
                res = max(res, cnt);
            }
            else{
                cnt = 0;
            }
        }
        return res;
    }
};