class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int res = 0;
        sort(arr.begin(), arr.end());
        for(int& x : arr){
            res = min(res + 1, x);
        }
        return res;
    }
};