class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int res = 0, j = 0, n = players.size(), m = trainers.size();
        for (int i = 0; j < m && i < n; i++)
        {
            while(j < m && players[i] > trainers[j]) j++;
            if(j<m && players[i] <= trainers[j]) res++, j++;
        }
        return res;
    }
};