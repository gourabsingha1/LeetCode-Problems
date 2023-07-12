// hash bobs candies
// num = sum / 2 - sumAlice is the number of candies alice is missing or having extra

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sumAlice = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
        int sumBob = accumulate(bobSizes.begin(),bobSizes.end(), 0);
        int num = (sumAlice + sumBob) / 2 - sumAlice;
        
        unordered_map<int, bool> checkBob;
        for (int i = 0; i < bobSizes.size(); i++)
        {
            checkBob[bobSizes[i]] = 1;
        }
        for (int i = 0; i < aliceSizes.size(); i++)
        {
            if(checkBob[aliceSizes[i] + num]) {
                return {aliceSizes[i], aliceSizes[i] + num};
            }
        }
        return {};
    }
};