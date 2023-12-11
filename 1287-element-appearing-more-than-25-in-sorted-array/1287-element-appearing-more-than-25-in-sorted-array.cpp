// brute force

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int cnt = 1, limit = arr.size() / 4;
        for(int i = 1; i < arr.size(); i++) {
            if(arr[i - 1] == arr[i]) {
                cnt++;
            }
            else {
                cnt = 1;
            }
            if(cnt > limit) {
                return arr[i];
            }
        }
        return arr[0];
    }
};