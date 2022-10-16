class Solution {
public:
    vector<vector<int>> PerAll2(int i, vector<vector<int>> &s, vector<int> &a){
        if(i==a.size()){
            s.push_back(a);
            return s;
        }
        for (int j = i; j < a.size(); j++)
        {
            swap(a[i],a[j]);
            PerAll2(i+1, s, a);
            swap(a[i],a[j]);
        }
        return s;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        return PerAll2(0, res, nums);
    }
};