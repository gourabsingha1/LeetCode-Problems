class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size(), j = 0;
        if(n & 1) return {};
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
                changed[j++] = changed[i];
            }
        }
        for(auto &[x, y] : m){
            if(y) return {};
        }
        return {changed.begin(), changed.begin() + j};
    }
};