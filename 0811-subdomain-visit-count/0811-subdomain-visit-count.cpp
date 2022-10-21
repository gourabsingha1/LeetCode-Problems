class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> res;
        
        unordered_map<string, int> m;
        for (string &s : cpdomains)
        {
            int j = 0;
            while(s[j] != ' '){
                j++;
            }
            int num = stoi(s.substr(0, j));
            
            for (int i = s.size() - 1; i >= j; i--)
            {
                if(s[i] == '.' || i == j){
                    m[s.substr(i+1, s.size() - i)] += num;
                }
            }
        }
        for(auto &x : m){
            res.push_back(to_string(x.second) + " " + x.first);
        }
        return res;
    }
};