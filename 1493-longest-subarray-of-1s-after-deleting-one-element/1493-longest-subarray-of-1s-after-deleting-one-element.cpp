// store count of 1s of all "1's subarrays" on the start and ending position of that subarray
// then res = max(res, leftSubarray + rightSubarray)

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size(), res = 0;
        bool foundZero = 0; // case: 1, 1, 1
        vector<pair<int, int>> mp(n); // index = [count of ones, start]
        for (int i = 0; i < n; i++)
        {
            if(nums[i] == 0) {
                foundZero = 1;
                continue;
            }

            int left = i, cnt = 0;
            while(i < n && nums[i]) {
                cnt++, i++;
            }
            res = max(res, cnt);

            mp[left] = {cnt, 1};
            int right = i - 1;
            if(left == right) {
                mp[right] = {cnt, -1};
            }
            else {
                mp[right] = {cnt, 0};
            }
        }

        if(!foundZero) res--;

        for (int i = 1; i < n - 1; i++)
        {

            if(mp[i - 1].second != 1 && mp[i + 1].second != 0 ) {
                res = max(res, mp[i - 1].first + mp[i + 1].first);
            }
        }
        cout<<endl;
        return res;
    }
};