class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> res;
        int ma = *max_element(candies.begin(), candies.end());
        for (auto& candy : candies) {
            if(candy + extraCandies >= ma) {
                res.push_back(1);
            }
            else {
                res.push_back(0);
            }
        }
        return res;
    }
};