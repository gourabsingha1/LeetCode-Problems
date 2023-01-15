// Scanline Algorithm
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> pre(1001, 0);
        for(auto &v : trips){
            int x = v[0], l = v[1], r = v[2];
            pre[l] += x;
            pre[r] -= x;
        }
        for (int i = 0; i < 1000; i++)
        {
            if(pre[i] > capacity) return 0;
            pre[i + 1] += pre[i];
        }
        return 1;
    }
};