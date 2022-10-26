class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        reverse(nums.begin(), nums.end());
        int res = 0;
        unordered_map<int,int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++;
            for (int j = i+1; j < nums.size(); j++)
            {
                for (int k = j+1; k < nums.size(); k++)
                {
                    int x = nums[i] + nums[j] + nums[k];
                    if(m[x]){
                        res+=m[x];
                    }
                }
            }
        }
        return res;
    }
};