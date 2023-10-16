class Solution {
public:
    // checks if index i has a subset companylist
    bool isSubset (vector<string>& companylist, int i, unordered_map<int, unordered_map<string, bool>>& indexHasCompany) {
        for(auto& company : companylist) {
            if(!indexHasCompany[i][company]) {
                return 0;
            }
        }
        return 1;
    }

    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        int n = favoriteCompanies.size();
        vector<int> res;
        unordered_map<int, unordered_map<string, bool>> indexHasCompany;
        for (int i = 0; i < n; i++)
        {
            for(auto& company : favoriteCompanies[i]) {
                indexHasCompany[i][company] = 1;
            }
        }

        // check for every ith companylist, if they are a subset
        for (int i = 0; i < n; i++)
        {
            bool found = 0;
            for (int j = 0; j < n; j++)
            {
                if(i == j || favoriteCompanies[i].size() > favoriteCompanies[j].size()) continue;
                if(isSubset(favoriteCompanies[i], j, indexHasCompany)) {
                    found = 1;
                    break;
                }
            }
            if(!found) {
                res.push_back(i);
            }
        }
        return res;
    }
};