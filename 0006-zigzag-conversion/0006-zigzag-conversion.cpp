class Solution {
public:
    int columns(int n, int numRows){
        int res = 0, deno = 2 * numRows - 2;
        if(!deno) return 1;
        for (int i = 0; i < n; i++)
        {
            if((i + deno) % deno == 0){
                res++, i += numRows - 1;
                int k = numRows - 2;
                while(i < n && k--){
                    res++, i++;
                }
            }
        }
        return res;
    }
    string convert(string s, int numRows) {
        string res, p;
        int n = s.size(), m = columns(n, numRows), k = 0;
        if(numRows == 1){
            return s;
        }
        else if(numRows == 2){
            res = s;
            int l = 0, r = (n + 1)/ 2;
            for (int i = 0; i < n; i++)
            {
                if(i & 1){
                    res[r++] = s[i];
                }
                else{
                    res[l++] = s[i];
                }
            }
            return res;
        }
        for (int i = 0; i < m; i++)
        {
            p += '#';
        }
        vector<string> zigzag(numRows, p);
        for (int i = 0; i < m && k < n; i++)
        {
            if(i & 1){
                for (int j = numRows - 2; j >= 1 && k < n; j--)
                {
                    zigzag[j][i] = s[k++];
                }
            }
            else{
                for (int j = 0; j < numRows && k < n; j++)
                {
                    zigzag[j][i] = s[k++];
                }
            }
        }
        for(auto &s : zigzag){
            for(auto &c : s){
                if(c != '#'){
                    res += c;
                }
            }
        }
        return res;
    }
};