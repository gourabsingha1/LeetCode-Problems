class Solution {
public:
    int minDeletions(string s) {
        int res = 0;
        vector<int> mp(26, 0), v;
        int mLast;
        for(char &c : s) mp[c-'a']++;
        for (int i = 0; i < 26; i++){
            if(mp[i]) v.push_back(mp[i]);
        }
        sort(v.rbegin(), v.rend());
        mLast = v[0];
        for (int i = 1; i < v.size(); i++){
            if(mLast <= v[i]){
                if(v[i-1] == 0) v[i-1]++;
                res += v[i] - v[i-1] + 1;
                v[i] = v[i-1] - 1;
            }
            mLast = v[i];
        }
        return res;
    }
};