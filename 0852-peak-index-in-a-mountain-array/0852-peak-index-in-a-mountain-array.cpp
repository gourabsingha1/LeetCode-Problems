class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0, high = arr.size() - 1;
        while(low <= high){
            int mid = high + (low - high) / 2;
            if(mid - 1 >= 0 && mid + 1 < arr.size() && arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]){
                return mid;
            }
            else if(arr[mid] > arr[mid + 1]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return -1;
    }
};