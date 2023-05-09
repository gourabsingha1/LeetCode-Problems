class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> LIS = {obstacles[0]}, res = {1};
        for (int i = 1; i < obstacles.size(); i++)
        {
            int lb = upper_bound(LIS.begin(), LIS.end(), obstacles[i]) - LIS.begin();
            if(lb == LIS.size()) {
                LIS.push_back(obstacles[i]);
            }
            else {
                LIS[lb] = obstacles[i];
            }
            res.push_back(lb + 1);
        }
        return res;
    }
};