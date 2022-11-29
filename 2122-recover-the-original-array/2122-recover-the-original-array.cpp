class Solution {
public:
    vector<int> recoverArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 1; i < n; i++)
        {
            int k = nums[i] - nums[0];
            if(k&1 || nums[i] == nums[i-1]) continue;

            vector<int> v1, v2;
            int j = 0;
            v1.push_back(nums[j]);
            for (int i = 1; i < n; i++)
            {
                if(j < v1.size() && nums[i] == v1[j] + k){
                    v2.push_back(nums[i]);
                    j++;
                }
                else{
                    v1.push_back(nums[i]);
                }
            }
            
            if(v1.size() == n/2){
                for (int i = 0; i < n/2; i++)
                {
                    v1[i] = (v1[i] + v2[i])/2;
                }
                return v1;
            }
        }
        return {};
    }
};