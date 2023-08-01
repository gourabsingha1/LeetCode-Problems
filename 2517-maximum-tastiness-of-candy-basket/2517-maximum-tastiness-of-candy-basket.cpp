// binary search answer
// int j = 0, int i = upper_bound(price[j] + mid)
// set j = i and keep incrementing i till k - 1 (we always select 0th candy)
// to check if k - 1 elements can be selected

class Solution {
public:
    bool isPossible(int mid, vector<int>& price, int k) {
        int j = 0;
        while(k--) {
            int i = upper_bound(price.begin(), price.end(), price[j] + mid) - price.begin();
            if(i == price.size()) {
                return 0;
            }
            j = i;
        }
        return 1;
    }

    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        int low = 0, high = 1e9;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(isPossible(mid, price, k - 1)) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return low;
    }
};