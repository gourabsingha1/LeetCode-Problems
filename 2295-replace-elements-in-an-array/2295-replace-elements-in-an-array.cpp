class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int,int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]] = i;
        }
        
        for(auto &x : operations){
            nums[m[x[0]]] = x[1];
            m[x[1]] = m[x[0]];
        }
        return nums;
    }
};