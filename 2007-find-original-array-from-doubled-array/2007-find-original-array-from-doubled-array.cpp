class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> res;
        int n = changed.size();
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            m[changed[i]]++;
        }
        sort(changed.begin(), changed.end());
        for (int i = 0; i < n; i++)
        {
            if(m[changed[i]] && m[2 * changed[i]]){
                m[changed[i]]--, m[2 * changed[i]]--;
                res.push_back(changed[i]);
            }
        }
        for(auto &[x, y] : m){
            if(y) return {};
        }
        return res;
    }
};