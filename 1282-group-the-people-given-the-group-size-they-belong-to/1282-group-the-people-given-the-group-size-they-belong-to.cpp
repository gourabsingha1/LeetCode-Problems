class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> res;
        vector<pair<int, int>> groupIndexPair;
        int n = groupSizes.size();
        for (int i = 0; i < n; i++)
        {
            groupIndexPair.push_back({groupSizes[i], i});
        }
        sort(groupIndexPair.begin(), groupIndexPair.end());
        for (int i = 0; i < n; i++)
        {
            int size = groupIndexPair[i].first;
            vector<int> temp;
            while(size--) {
                temp.push_back(groupIndexPair[i++].second);
            }
            i--;
            res.push_back(temp);
        }
        return res;
    }
};