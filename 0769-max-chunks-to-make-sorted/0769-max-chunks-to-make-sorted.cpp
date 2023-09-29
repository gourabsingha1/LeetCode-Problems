class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int res = 0, n = arr.size(), mx = 0;
        for (int i = 0; i < n; i++)
        {
            mx = max(mx, arr[i]);
            if(mx == i) {
                res++;
            }
        }
        return res;
    }
};