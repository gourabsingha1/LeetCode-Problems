// since we start from house 0, we can keep a sum variable
// which calculates the time needed to reach the ith house
// if a metal exists in ith house, we record that sum to that metal

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int pickSum = 0, M = 0, P = 0, G = 0, travelSum = 0;
        for (int i = 0; i < garbage.size(); i++)
        {
            for(auto& type : garbage[i]) {
                if(type == 'M') {
                    M = travelSum;
                }
                if(type == 'P') {
                    P = travelSum;
                }
                if(type == 'G') {
                    G = travelSum;
                }
            }
            pickSum += garbage[i].size(); // all garbages will be picked at some point
            
            if(i < travel.size()) {
                travelSum += travel[i];
            }
        }
        return pickSum + M + P + G;
    }
};