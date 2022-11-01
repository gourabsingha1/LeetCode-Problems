class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int res = INT_MAX;
        unordered_map<int,int> m;
        int j = 0;
        for (int i = 0; i < cards.size(); i++)
        {
            m[cards[i]]++;
            while(m[cards[i]] == 2){
                m[cards[j]]--;
                j++;
                res = min(res, i-j+2);
            }
        }
        if(res == INT_MAX){
            res = -1;
        }
        return res;
    }
};