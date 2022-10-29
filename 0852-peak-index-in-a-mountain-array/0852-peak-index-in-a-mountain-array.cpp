class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0, h = arr.size() - 1;
        while(l < h){
            int m = (l + h)/2;
            if(l < m && arr[m-1] < arr[m] && arr[m] > arr[m+1]){
                return m;
            }
            else if(arr[m] > arr[m+1]){
                h = m - 1;
            }
            else{
                l = m + 1;
            }
        }
        return l;
    }
};