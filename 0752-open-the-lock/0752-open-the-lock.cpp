class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int level = 0;
        unordered_map<string, bool> seen;
        for(auto& s : deadends) seen[s] = 1;
        if(seen[target] || seen["0000"]) return -1;
        queue<string> q;
        q.push("0000");
        seen["0000"] = 1;
        while(q.size()){
            int t = q.size();
            while(t--){
                string s = q.front();
                q.pop();
                if(s == target){
                    return level;
                }
                for (int i = 0; i < s.size(); i++)
                {
                    char temp = s[i];
                    s[i]++;
                    if(s[i] > '9') {
                        s[i] = '0';
                    }
                    else if(s[i] < '0') {
                        s[i] = '9';
                    }
                    if(!seen[s]){
                        q.push(s);
                        seen[s] = 1;
                    }
                    s[i] = temp;
                    s[i]--;
                    if(s[i] > '9') {
                        s[i] = '0';
                    }
                    else if(s[i] < '0') {
                        s[i] = '9';
                    }
                    if(!seen[s]){
                        q.push(s);
                        seen[s] = 1;
                    }
                    s[i] = temp;
                }
            }
            level++;
        }
        return -1;
    }
};