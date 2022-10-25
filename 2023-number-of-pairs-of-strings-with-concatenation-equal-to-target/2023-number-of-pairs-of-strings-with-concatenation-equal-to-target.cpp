
class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int res = 0;
        unordered_map<string,int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++;
        }
        for(auto &x : m){
            string prefix = x.first;
            if(prefix.size() > target.size()){
                continue;
            }
            string suffix = target.substr(prefix.size());
            if(target.substr(0,prefix.size()) == prefix){
                res += m[prefix]*m[suffix];
                if(prefix == suffix){
                    res -= m[prefix];
                }
            }
        }
        return res;
    }
};