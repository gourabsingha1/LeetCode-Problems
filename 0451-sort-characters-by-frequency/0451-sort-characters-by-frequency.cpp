class Solution {
public:
    string frequencySort(string s) {
        string res;
        vector<pair<int, int>>v;
        for (int i = 0; i < 75; i++) v.push_back({0,0});
        
        for(char &c : s){
            v[c-'0'].second = c-'0';
            v[c-'0'].first++;
        }
        sort(v.rbegin(), v.rend());
        for(auto &[x,y] : v){
            if(!x) return res;
            while(x--){
                res.push_back(y+'0');
            }
        }
        return res;
    }
};