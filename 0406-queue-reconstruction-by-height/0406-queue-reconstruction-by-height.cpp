// sort such that h[i] > h[i + 1] && k[i] >= i
// k[i] >= i so that we can insert within boundary
class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        if(a[0] == b[0]) {
            return a[1] < b[1];
        }
        return a[0] > b[0];
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> res;
        sort(people.begin(), people.end(), cmp);
        for (int i = 0; i < people.size(); i++)
        {
            res.insert(res.begin() + people[i][1], people[i]);
        }
        return res;
    }
};