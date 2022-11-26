class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> res;
        unordered_map<string,int> ms;
        for(auto &x : words){
            vector<int> m(26, 0);
            int mi = 'z';
            for(auto &y : x){
                m[y-'a']++;
                mi = min(mi, y-'a');
            }
            ms[x] = m[mi];
        }
        for(auto &x : queries){
            vector<int> m(26, 0);
            int mi = 'z';
            for(auto &y : x){
                m[y-'a']++;
                mi = min(mi, y-'a');
            }
            int c = 0;
            for(auto y : words){
                if(ms[y] > m[mi]){
                    c++;
                }
            }
            res.push_back(c);
        }
        return res;
    }
};