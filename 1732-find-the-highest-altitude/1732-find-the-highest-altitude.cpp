class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum = 0, res = 0;
        for(auto& num : gain) {
            sum += num;
            res = max(res, sum);
        }
        return res;
    }
};