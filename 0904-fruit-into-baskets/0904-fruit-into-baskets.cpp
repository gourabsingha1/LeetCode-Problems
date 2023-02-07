class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size(), j = 0, res = 0;
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            m[fruits[i]]++;
            while(m.size() > 2){
                m[fruits[j]]--;
                if(!m[fruits[j]]){
                    m.erase(fruits[j]);
                }
                j++;
            }
            res = max(res, i - j + 1);
        }
        return res;
    }
};