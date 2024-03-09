// cnt keeps count of maxFreqElement
// if we find a new max freq, update cnt to 1

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        int mx = 0, cnt = 1;
        for(auto& x : nums) {
            if(mx < ++mp[x]) {
                mx = mp[x];
                cnt = 1;
            }
            else if(mx == mp[x]) {
                cnt++;
            }
        }
        return mx * cnt;
    }
};