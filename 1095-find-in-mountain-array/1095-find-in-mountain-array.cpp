/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int peakIndexInMountainArray(MountainArray &mountainArr) {
        int n = mountainArr.length(), low = 0, high = n - 1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(mountainArr.get(mid) < mountainArr.get(mid + 1)){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        if(low == n) return -1;
        return low;
    }
    
    int binarySearch(bool checkLeft, int low, int high, int target, MountainArray &mountainArr) {
        while(low <= high){
            int mid = high + (low - high) / 2;
            if(mountainArr.get(mid) == target){
                return mid;
            }
            else if(mountainArr.get(mid) > target){
                if(checkLeft) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            else{
                if(checkLeft) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
        }
        return 1e5;
    }
    
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak = peakIndexInMountainArray(mountainArr);
        int left = binarySearch(1, 0, peak, target, mountainArr), right = binarySearch(0, peak, mountainArr.length() - 1, target, mountainArr);
        int res = min(left, right);
        if(res != 1e5) return res;
        return -1;
    }
};