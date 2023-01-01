class Solution {
public:
    set<vector<int>> SubND(int i, vector<int> v, set<vector<int>> &s, vector<int> &a){
        if(i == a.size()){
            sort(v.begin(), v.end());
            s.insert(v);
            return s;
        }
        v.push_back(a[i]);
        SubND(i+1, v, s, a); // pick
        v.pop_back();
        SubND(i+1, v, s, a); // not pick
        return s;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> st;
        st = SubND(0, {}, st, nums);
        vector<vector<int>> res;
        res.assign(st.begin(), st.end());
        return res;
    }
};