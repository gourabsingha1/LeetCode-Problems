// brute force

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> res;
        for (int i = 0; i < l.size(); i++)
        {
            vector<int> temp = nums;
            sort(temp.begin() + l[i], temp.begin() + r[i] + 1);

            int diff = temp[l[i] + 1] - temp[l[i]], flag = 1;
            for (int j = l[i] + 1; j <= r[i]; j++)
            {
                if(temp[j] - temp[j - 1] != diff) {
                    flag = 0;
                    break;
                }
            }
            res.push_back(flag);
        }
        return res;
    }
};