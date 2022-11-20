class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        vector<int> res;
        int n = nums.size(), c = 1, d = 1;
        vector<int> pre(n, 0);
        if(k == 1){
            for (int i = 1; i < n-1; i++)
            {
                res.push_back(i);
            }
            return res;
        }

        for (int i = 1; i < n; i++)
        {
            if(nums[i-1] >= nums[i]){
                c++;
                if(c >= k && i+1<n){
                    pre[i+1]++;
                }
            }
            else{
                c = 1;
            }

            if(nums[n-i] >= nums[n-1-i]){
                d++;
                if(d >= k && n-2-i>=0){
                    pre[n-2-i]++;
                }
            }
            else{
                d = 1;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if(pre[i] == 2){
                res.push_back(i);
            }
        }
        return res;
    }
};