// product of all (zeroCnt + 1)'s bw two 1's

class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int n = nums.size(), res = 1, M = 1e9 + 7, allZero = 1;
        for (int i = 0; i < n; i++)
        {
            if(nums[i] == 1) {
                int cnt = 1;
                i++;
                while(i < n && nums[i] == 0) {
                    cnt++, i++;
                }
                if(i < n) {
                    res = (1LL * res * cnt) % M;
                }
                i--;
                allZero = 0;
            }
        }
        if(allZero) return 0;
        return res;
    }
};

// 01 001 001
// 01 0010 01
// 01 00100 1
// 010 01 001
// 010 010 01
// 010 0100 1
// 0100 1 001
// 0100 10 01
// 0100 100 1