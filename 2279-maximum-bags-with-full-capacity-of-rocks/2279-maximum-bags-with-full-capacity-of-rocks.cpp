class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size(), res = 0;
        vector<int> space(n);
        for (int i = 0; i < n; i++)
        {
            space[i] = capacity[i] - rocks[i];
        }
        sort(space.begin(), space.end());
        for (int i = 0; i < n; i++)
        {
            if(space[i] <= additionalRocks){
                additionalRocks -= space[i];
                res++;
            }
            else{
                break;
            }
        }
        return res;
    }
};