class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        int i = 0, j = 0, n = firstList.size(), m = secondList.size();
        while(i < n && j < m){
            int x = max(firstList[i][0], secondList[j][0]), y = min(firstList[i][1], secondList[j][1]);
            if(x <= y){
                res.push_back({x, y});
            }
            if(firstList[i][1] < secondList[j][1]){
                i++;
            }
            else{
                j++;
            }
        }
        return res;
    }
};