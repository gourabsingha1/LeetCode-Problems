// try all combinations of requests. if achievable, add to result

class Solution {
public:
    bool isAchievable(vector<int>& subset, int n, vector<vector<int>>& requests) {
        vector<int> buildings(n, 0);
        for (int i = 0; i < subset.size(); i++)
        {
            int from = requests[subset[i]][0], to = requests[subset[i]][1];
            buildings[from]--, buildings[to]++;
        }
        for (int i = 0; i < n; i++)
        {
            if(buildings[i]) {
                return 0;
            }
        }
        return 1;
    }

    int helper(vector<int>& subset, int ind, int n, vector<vector<int>>& requests) {
        if(ind < 0) {
            if(!isAchievable(subset, n, requests)) {
                return 0;
            }
            return subset.size();
        }
        subset.push_back(ind);
        int take = helper(subset, ind - 1, n, requests);
        subset.pop_back();
        int notTake = helper(subset, ind - 1, n, requests);
        return max(take, notTake);
    }
    
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> subset;
        return helper(subset, requests.size() - 1, n, requests);
    }
};