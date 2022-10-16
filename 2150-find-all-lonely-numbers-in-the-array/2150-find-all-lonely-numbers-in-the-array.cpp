class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        map<int,int>m;
        for(int &x : nums){
            m[x]++;
        }
        vector<int> res;
        for(auto &x : m){
            if(x.second == 1 && m[x.first - 1]==0 && m[x.first + 1]==0){
                res.push_back(x.first);
                x.second = 0;
            }
        }
        return res;
    }
};