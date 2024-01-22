// since numbers are from 1 to n, treat numbers as indices
// set nums[nums[i] - 1] to its negation
// if in one scan, a neg number is found, then nums[i] is the repeated element
// in another scan if nums[i] > 0, the missing element is i + 1
// bacause that index wasn't found and hence marked in the first scan

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int a, b, n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int ind = abs(nums[i]) - 1;
            if(nums[ind] > 0){
                nums[ind] *= -1;
            }
            else{
                a = ind + 1;
            }
        }
        
        for (int i = 0; i < n; i++)
        {
            if(nums[i] > 0){
                b = i + 1;
                break;
            }
        }
        return {a, b};
    }
};