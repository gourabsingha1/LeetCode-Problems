class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = 1e9;
        while(low < high) {
            int mid = (low + high) / 2, curr = 0;
            for(auto& pile : piles) {
                curr += (pile + mid - 1) / mid;
            }
            if(curr > h) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }
        return high;
    }
};