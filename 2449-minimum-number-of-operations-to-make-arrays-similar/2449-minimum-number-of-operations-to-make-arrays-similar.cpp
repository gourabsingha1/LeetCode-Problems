class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        long long res = 0;
        sort(nums.begin(), nums.end());
        sort(target.begin(), target.end());
        int n = nums.size(), c = 0, eNums = 0, oNums = 0, eTar = 0, oTar = 0;
        while(eNums < n && oNums <= n || eNums <= n && oNums < n){
            while(eNums < n && nums[eNums]&1){
                eNums++, c++;
            }
            while(oNums < n && nums[oNums]%2 == 0){
                oNums++, c++;
            }
            while(eTar < n && target[eTar]&1) eTar++;
            while(oTar <n && target[oTar]%2 == 0) oTar++;
            if(eNums < n && eTar < n) res += abs(nums[eNums++] - target[eTar++])/2;
            if(oNums < n && oTar < n) res += abs(nums[oNums++] - target[oTar++])/2;
        }
        return res/2;
    }
};