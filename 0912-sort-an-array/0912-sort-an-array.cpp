class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> bucket(1e5 + 1, 0);
        int d = 5 * (1e4);
        for (int& x : nums){
            bucket[x + d]++;
        }
        for (int i = 0, j = 0; i < 1e5 + 1; i++){
            while(bucket[i]--){
                nums[j++] = i - d;
            }
        }
        return nums;
    }
};