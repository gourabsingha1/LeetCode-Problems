class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int i = 0, n = arr.size(), mn = -1, mnPos = -1;
        while(i < n) {
            if(mn < arr[i]) {
                mn = arr[i];
                mnPos = i;
            }
            int left = i && mnPos == i, right = 0, cur = arr[i++];
            while(i < n && cur > arr[i]) {
                i++, right++;
            }
            if(i < n && left + right >= k) {
                return cur;
            }
        }
        return *max_element(arr.begin(), arr.end());
    }
};