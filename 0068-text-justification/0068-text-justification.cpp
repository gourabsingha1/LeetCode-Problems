class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int i = 0, j = 0, n = words.size();
        while(i < n) {
            int cntChar = 0, cntSpace = 0;
            j = i;
            while(i < n && cntChar + cntSpace + words[i].size() <= maxWidth) {
                cntChar += words[i++].size(), cntSpace++;
            }
            if(i == n) {
                break;
            }

            cntSpace--;
            int x = maxWidth - cntChar, rem = 0;
            if(cntSpace) {
                rem = x % cntSpace, x /= cntSpace;
            }
            string space;
            while(x--) {
                space += " ";
            }
            vector<string> spaces(cntSpace, space);
            while(rem--) {
                spaces[rem] += " ";
            }

            string cur;
            int ind = 0;
            while(j < i && cur.size() < maxWidth) {
                cur += words[j++];
                if(ind < cntSpace) {
                    cur += spaces[ind++];
                }
            }
            if(cntSpace == 0) {
                cur += space;
            }
            res.push_back(cur);
        }

        string last;
        while(j < n) {
            last += words[j++] + " ";
        }
        last.pop_back();
        while(last.size() < maxWidth) {
            last += " ";
        }
        res.push_back(last);
        return res;
    }
};