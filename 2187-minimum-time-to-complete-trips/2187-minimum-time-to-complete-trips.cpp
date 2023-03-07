class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long res = LONG_LONG_MAX, low = 0, high = 1e14;
        while(low <= high) {
            long long mid = (low + high) / 2, currTotal = 0;
            for (int i = 0; i < time.size() && currTotal < totalTrips; i++)
            {
                currTotal += mid / time[i];
            }
            if(currTotal < totalTrips) {
                low = mid + 1;
            }
            else {
                res = min(res, mid);
                high = mid - 1;
            }
        }
        return res;
    }
};