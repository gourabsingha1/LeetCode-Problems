class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1, h = *max_element(nums.begin(), nums.end()), res = INT_MAX;
        while(l <= h){
            int m = h + (l-h)/2, sum = 0;
            for(int &x : nums){
                sum += ((x+m-1)/m);
            }
            if(sum > threshold){
                l = m + 1;
            }
            else{
                res = min(res, m);
                h = m - 1;
            }
        }
        return res;
    }
};