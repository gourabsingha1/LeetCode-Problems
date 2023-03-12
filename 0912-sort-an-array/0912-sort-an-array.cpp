class Solution {
public:
    // merge sort
    void mergeSort(int low, int high, vector<int>& nums) {
        if(low >= high) {
            return;
        }

        // divide
        int mid = (low + high) / 2;
        mergeSort(low, mid, nums);
        mergeSort(mid + 1, high, nums);

        // merge
        merge(low, mid, high, nums);
    }
    void merge(int low, int mid, int high, vector<int>& nums) {
        if (low >= high) return;
        int l = low, r = mid + 1, k = 0, size = high - low + 1;
        vector<int> sorted(size, 0);
        while (l <= mid and r <= high)
            sorted[k++] = nums[l] < nums[r] ? nums[l++] : nums[r++];
        while (l <= mid) 
            sorted[k++] = nums[l++];
        while (r <= high) 
            sorted[k++] = nums[r++];
        for (k = 0; k < size; k++)
            nums[k + low] = sorted[k];
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(0, nums.size() - 1, nums);
        return nums;
    }
};