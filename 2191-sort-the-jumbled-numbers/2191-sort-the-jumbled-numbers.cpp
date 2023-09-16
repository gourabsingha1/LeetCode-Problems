class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> newNumInd(n);
        for (int i = 0; i < n; i++)
        {
            int x = 0, num = nums[i], shift = 1;
            if(num == 0) {
                x = mapping[0];
            }
            else {
                while(num) {
                    x = mapping[num % 10] * shift + x;
                    num /= 10, shift *= 10;
                }
            }
            newNumInd[i] = {x, i};
        }
        sort(newNumInd.begin(), newNumInd.end());
        vector<int> res(n);
        for (int i = 0; i < n; i++)
        {
            res[i] = nums[newNumInd[i].second];
        }
        return res;
    }
};