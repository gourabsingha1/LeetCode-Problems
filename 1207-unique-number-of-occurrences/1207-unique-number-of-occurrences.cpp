// Counting sort
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = 2001, mp[2001] = {};
        for(auto& num : arr) {
            mp[num + 1000]++;
        }
        sort(mp, mp + n);
        for (int i = 1; i < n; i++)
        {
            if(mp[i] && mp[i - 1] == mp[i]) {
                return 0;
            }
        }
        return 1;
    }
};