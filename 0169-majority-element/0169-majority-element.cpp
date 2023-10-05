class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = INT_MAX, cnt = 0;
        for(auto& num : nums) {
            if(num == res) {
                cnt++;
            }
            else if(cnt == 0) {
                res = num;
            }
            else {
                cnt--;
            }  
        }
        return res;
    }
};