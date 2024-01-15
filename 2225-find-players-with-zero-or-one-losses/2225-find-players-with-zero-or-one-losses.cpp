// brute force

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int> zero, one;
        unordered_map<int, int> lostFreq;
        for(auto& match : matches) {
            lostFreq[match[1]]++;
        }
        for(auto& [player, freq] : lostFreq) {
            if(freq == 1) {
                one.push_back(player);
            }
        }
        for(auto& match : matches) {
            if(!lostFreq[match[0]]) {
                zero.push_back(match[0]);
                lostFreq[match[0]] = 1; // don't want duplicates
            }
        }
        sort(zero.begin(), zero.end());
        sort(one.begin(), one.end());
        return {zero, one};
    }
};