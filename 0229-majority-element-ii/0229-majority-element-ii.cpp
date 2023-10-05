// similar to majority element I

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int res1 = INT_MAX, res2 = INT_MAX, cnt1 = 0, cnt2 = 0, n = nums.size();
        for(auto& num : nums) {
            if(res1 == num) {
                cnt1++;
            }
            else if(res2 == num) {
                cnt2++;
            }
            else if(cnt1 == 0) {
                cnt1 = 1;
                res1 = num;
            }
            else if(cnt2 == 0) {
                cnt2 = 1;
                res2 = num;
            }
            else {
                cnt1--, cnt2--;
            }
        }
        
        cnt1 = 0, cnt2 = 0;
        for(auto& num : nums) {
            cnt1 += num == res1;
            cnt2 += num == res2;
        }

        if(cnt1 > n / 3) {
            res.push_back(res1);
        }
        if(cnt2 > n / 3) {
            res.push_back(res2);
        }
        return res;
    }
};