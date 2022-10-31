class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int res = 0, oddMax = 0, evenMax = 0;
        nums.push_back(INT_MIN); // for the boudary case
        vector<int> temp = nums;

        for (int i = 0; i < nums.size()-1; i++)
        {
            if(i&1){
                if(nums[i] <= nums[i-1]){
                    int d = nums[i-1] - nums[i] + 1;
                    nums[i-1] -= d;
                    oddMax += d;
                }
                if(nums[i] <= nums[i+1]){
                    int d = nums[i+1] - nums[i] + 1;
                    nums[i+1] -= d;
                    oddMax += d;
                }
            }
            else{
                if(i>0 && temp[i] <= temp[i-1]){
                    int d = temp[i-1] - temp[i] + 1;
                    temp[i-1] -= d;
                    evenMax += d;
                }
                if(temp[i] <= temp[i+1]){
                    int d = temp[i+1] - temp[i] + 1;
                    temp[i+1] -= d;
                    evenMax += d;
                }
            }
        }
        return min(oddMax, evenMax);
    }
};