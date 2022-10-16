class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int,int>m;
        for(int &x : nums){
            m[x]++;
        }
        vector<int> res;
        for(int &x : nums){
            if(m[x]==1 && !m[x - 1] && !m[x + 1]){
                res.push_back(x);
                m[x] = 0;
            }
        }
        return res;
    }
};