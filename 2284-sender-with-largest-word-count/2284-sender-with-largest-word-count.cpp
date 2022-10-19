class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string, int> m;
        int ma = 0;
        string res;
        for (int i = 0; i < senders.size(); i++)
        {
            int cnt = 1;
            for(char &c : messages[i]){
                if(c == ' '){
                    cnt++;
                }
            }
            m[senders[i]] += cnt;

            if(m[senders[i]] > ma || m[senders[i]] == ma && senders[i] > res){
                res = senders[i];
                ma = m[senders[i]];
            }
        }

        return res;
    }
};