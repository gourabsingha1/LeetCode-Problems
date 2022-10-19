class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string, int> m;
        int ma = 0;
        for (int i = 0; i < senders.size(); i++)
        {
            int cnt = 1;
            for(char &c : messages[i]){
                if(c == ' '){
                    cnt++;
                }
            }
            m[senders[i]] += cnt;
            ma = max(ma, m[senders[i]]);
        }

        priority_queue<string> res;
        for(auto &x : m){
            if(ma == x.second){
                res.push(x.first);
            }
        }
        return res.top();
    }
};