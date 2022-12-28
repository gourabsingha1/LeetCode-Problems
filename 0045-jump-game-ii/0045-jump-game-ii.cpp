class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0, curr = 0, ma = 0;
        for (int i = 0; i < nums.size()-1; i++)
        {
            ma = max(ma, nums[i] + i);
            if(i == curr){
                res++;
                curr = ma;
            }
        }
        return res;
    }
};