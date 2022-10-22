class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size(), res = 0;

        // we have to get rid of the -ve values in order for indexing to work 
        for (int i = 0; i < n; i++)
        {
            if(nums[i] < 0){
                nums[i] = 0;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if(nums[i] != INT_MIN){
                int x = abs(nums[i]) - 1;
                if(x >= 0 && x < n){
                    if(!nums[x]){
                        nums[x] = INT_MIN;
                    }
                    else if(nums[x] > 0){
                        nums[x] *= (-1);
                    }
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            if(nums[i] >= 0){
                return i+1;
            }
            // cout<<nums[i]<<" ";
        }
        return n + 1;
    }
};