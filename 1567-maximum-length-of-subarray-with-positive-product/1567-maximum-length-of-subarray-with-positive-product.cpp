class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int j = 0, res = 0, firstNeg = -1, lastNeg = -1, neg = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[i]){
                if(nums[i] < 0){
                    neg++;
                    if(firstNeg == -1) firstNeg = i;
                    if(lastNeg == -1) lastNeg = i;
                }
                if(neg%2==0){
                    res = max(res, i+1-j);
                }
                else{
                    res = max({res, i-firstNeg, lastNeg-j});
                }
            }
            else{
                j = i+1, firstNeg = -1, lastNeg = -1, neg = 0;
            }
        }
        return res;
    }
};