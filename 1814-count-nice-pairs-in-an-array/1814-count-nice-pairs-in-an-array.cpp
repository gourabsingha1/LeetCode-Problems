// 14 + (29 + x) = 41 + x, here 41 - 14 = 29
// need to find no of elements with the same difference occured before i

class Solution {
public:
    int rev(int num) {
        int res = 0;
        while(num) {
            res = res * 10 + num % 10;
            num /= 10;
        }
        return res;
    }

    int countNicePairs(vector<int>& nums) {
        int res = 0, M = 1e9 + 7;
        unordered_map<int, int> mp;
        for(auto& num : nums) {
            int diff = num - rev(num);
            res = (res + mp[diff]++) % M;
        }
        return res;
    }
};