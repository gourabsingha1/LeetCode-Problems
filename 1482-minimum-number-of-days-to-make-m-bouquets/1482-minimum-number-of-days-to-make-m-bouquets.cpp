class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = 0, high = 1e9, n = bloomDay.size();
        if(1LL * m * k > n) {
            return -1;
        }
        while(low <= high) {
            int mid = high + (low - high) / 2, cntBouquet = 0, cntConsecutive = 0;
            for (int i = 0; i < n; i++)
            {
                if(bloomDay[i] <= mid) {
                    cntConsecutive++;
                }
                else {
                    cntConsecutive = 0;
                }
                if(cntConsecutive == k) {
                    cntBouquet++;
                    cntConsecutive = 0;
                }
            }
            if(cntBouquet < m) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return low;
    }
};