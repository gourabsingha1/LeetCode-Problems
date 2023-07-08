class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        set<int> st(nums.begin(), nums.end());
        for (int i = 0; i < moveFrom.size(); i++)
        {
            if(st.count(moveFrom[i])) {
                st.erase(moveFrom[i]);
                st.insert(moveTo[i]);
            }
        }
        vector<int> res(st.begin(), st.end());
        return res;
    }
};