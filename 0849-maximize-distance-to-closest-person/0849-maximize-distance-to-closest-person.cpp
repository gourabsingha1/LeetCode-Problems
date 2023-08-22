class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int res = 1, n = seats.size(), first = -1, last = n;
        for (int i = 0; i < n; i++)
        {
            if(seats[i]) {
                res = max(res, (i - last) / 2);
                last = i;
                if(first == -1) {
                    first = i;
                }
            }
        }
        res = max({res, first, n - 1 - last});
        return res;
    }
};