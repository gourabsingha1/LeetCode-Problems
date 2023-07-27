// want all computers to run simultaneously
// set batteries which has batteries[i] >= time (mid) to a computer
// for batteries[i] < time, sum all such values
// and distribute to remaining computers

class Solution {
public:
    bool isPossible(long long time, int n, vector<int>& batteries) {
        long long sum = 0;
        for (int i = 0; i < batteries.size(); i++)
        {
            if(batteries[i] >= time) {
                n--;
            }
            else {
                sum += batteries[i];
            }
        }
        if(n <= 0) return 1;
        return sum / n >= time;
    }

    long long maxRunTime(int n, vector<int>& batteries) {
        long long low = 0, high = 1e14;
        while(low <= high) {
            long long mid = (low + high) / 2;
            if(isPossible(mid, n, batteries)) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return high;
    }
};