// binary search on speed
// add ceil values of time (dist / speed) till n - 1 index
// because we are rouding up the time till n - 1 index

class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low = 1, high = 1e7 + 1;
        while(low < high) {
            int mid = (low + high) / 2;
            double totalHour = 0;
            for (int i = 0; i < dist.size() - 1; i++)
            {
                totalHour += (dist[i] + mid - 1) / mid;
            }
            totalHour += (double) dist.back() / mid;
            if(totalHour <= hour) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }
        if(high == 1e7 + 1) {
            return -1;
        }
        return high;
    }
};