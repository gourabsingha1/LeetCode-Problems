// alternative: find the first element whose no of smaller elements on left + right >= k
// otherwise answer will always be the max_element
// at left, there can at max be 1 element since the bigger ones eat smaller ones
// at right, we can do one pass since cur will eat the most elements

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