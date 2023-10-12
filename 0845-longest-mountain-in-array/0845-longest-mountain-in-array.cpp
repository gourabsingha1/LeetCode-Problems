class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int res = 0, n = arr.size();
        for (int i = 0; i < n; i++)
        {
            int inc = 1;
            while(i + 1 < n && arr[i] < arr[i + 1]) {
                inc++, i++;
            }
            int dec = 1;
            while(i + 1 < n && arr[i] > arr[i + 1]) {
                dec++, i++;
            }
            
            if(inc >= 2 && dec >= 2) { // check mountain array condition
                res = max(res, inc + dec - 1);
            }
            if(inc > 1 || dec > 1) {
                i--;
            }
        }
        return res;
    }
};