class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> res(pref.size(), 0);
        res[0] = pref[0];
        int x = res[0];
        for (int i = 1; i < pref.size(); i++)
        {
            res[i] = x^pref[i];
            x ^= res[i];
        }
        return res;
    }
};