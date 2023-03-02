class Solution {
public:
    int compress(vector<char>& chars) {
        int j = 0, n = chars.size();
        for (int i = 0; i < n; i++)
        {
            int cnt = 1;
            while(i + 1 < n && chars[i] == chars[i + 1]){
                i++, cnt++;
            }
            chars[j++] = chars[i];
            if(cnt > 1) {
                string num = to_string(cnt);
                for(auto& c : num) {
                    chars[j++] = c;
                }
            }
        }
        return j;
    }
};