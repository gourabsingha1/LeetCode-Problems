class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size(), res = 0;
        unordered_map<int, int> m;
        for (int i = 0, j = 0; i < n; i++)
        {
            m[fruits[i]]++;
            while(m.size() > 2){
                m[fruits[j]]--;
                if(!m[fruits[j]]){
                    m.erase(fruits[j]);
                }
                j++;
            }
            int fruitsCnt = i - j + 1;
            res = max(res, fruitsCnt);
        }
        return res;
    }
};