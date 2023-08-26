// keep a window of length <= maxWidth
// if there are 17 spaces and we have 5 places, then the space distribution is 4 + 4 + 3 + 3 + 3

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int i = 0, j = 0, n = words.size();
        while(i < n) {
            // make the window
            int cntChar = 0, cntSpace = 0;
            j = i;
            while(i < n && cntChar + cntSpace + words[i].size() <= maxWidth) {
                cntChar += words[i++].size(), cntSpace++;
            }
            // last window
            if(i == n) {
                break;
            }

            // make space array
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

            // push the window
            string cur;
            int ind = 0;
            while(j < i && cur.size() < maxWidth) {
                cur += words[j++];
                if(ind < cntSpace) {
                    cur += spaces[ind++];
                }
            }
            // when theres only one word in a window, push space at end
            if(cntSpace == 0) {
                cur += space;
            }
            res.push_back(cur);
        }

        // last window
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