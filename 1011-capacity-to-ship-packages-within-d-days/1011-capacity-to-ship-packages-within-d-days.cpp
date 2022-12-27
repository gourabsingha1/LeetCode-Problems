class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end()), h = accumulate(weights.begin(), weights.end(), 0);
        while(l <= h){
            int mid = h + (l-h)/2, sum = 0;
            int currDays = 1;
            for (int i = 0; i < weights.size(); i++)
            {
                sum += weights[i];
                if(sum > mid){
                    currDays++;
                    sum = weights[i];
                }
            }
            if(currDays > days){
                l = mid + 1;
            }
            else{
                h = mid - 1;
            }
        }
        return l;
    }
};