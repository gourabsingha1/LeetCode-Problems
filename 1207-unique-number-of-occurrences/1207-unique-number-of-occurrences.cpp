class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp, seen;
        for(auto& num : arr) {
            mp[num]++;
        }
        for(auto& [key, val] : mp) {
            if(seen[val]) {
                return 0;
            }
            seen[val] = 1;
        }
        return 1;
    }
};