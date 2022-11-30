class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int ma = INT_MIN, mi = INT_MAX, a = 0, b = 0, n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if(ma < nums[i]){
                ma = nums[i];
                a = i+1;
            }
            if(mi > nums[i]){
                mi = nums[i];
                b = i+1;
            }
        }
        return min({min(a, b)+n+1-max(a,b), max(a,b), n+1-min(a,b)});
    }
};