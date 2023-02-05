class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        unordered_map<char, bool> m = {{'a', 1}, {'e', 1}, {'i', 1}, {'o', 1}, {'u', 1}};
        vector<int> nums(n), res;
        for (int i = 0; i < n; i++)
        {
            if(m[words[i][0]] && m[words[i][words[i].size() - 1]]){
                nums[i] = 1;
            }
        }
        for (int i = 1; i < n; i++)
        {
            nums[i] += nums[i - 1];
        }
        for (int i = 0; i < queries.size(); i++)
        {
            int l = queries[i][0] - 1, r = queries[i][1];
            if(l < 0){
                res.push_back(nums[r]);
            }
            else{
                res.push_back(nums[r] - nums[l]);
            }
        }
        return res;
    }
};