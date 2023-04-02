class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> res;
        sort(potions.begin(), potions.end());
        for(auto& spell : spells) {
            int low = 0, high = potions.size() - 1;
            while(low <= high) {
                int mid = high + (low - high) / 2;
                if(1LL * spell * potions[mid] < success) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
            res.push_back(potions.size() - low);
        }
        return res;
    }
};