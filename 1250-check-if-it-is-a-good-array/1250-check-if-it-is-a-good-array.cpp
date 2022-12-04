class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int gc = nums[0];
        for(int &x : nums){
            gc = __gcd(gc, x);
            if(gc == 1) return 1;
        }
        return 0;
    }
};