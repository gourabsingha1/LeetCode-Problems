class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        for (int& asteroid : asteroids)
        {
            while(res.size() && res.back() > 0 && asteroid < 0){
                if(res.back() < -asteroid) {
                    res.pop_back();
                }
                else if(res.back() == -asteroid) {
                    asteroid = 0;
                    res.pop_back();
                }
                else {
                    asteroid = 0;
                }
            }
            if(asteroid){
                res.push_back(asteroid);
            }
        }
        return res;
    }
};