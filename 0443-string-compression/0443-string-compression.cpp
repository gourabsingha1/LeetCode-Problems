class Solution {
public:
    int compress(vector<char>& chars) {
        int c = 1, res = 1, j = 0;
        for (int i = 0; i < chars.size() - 1; i++)
        {
            if(chars[i] == chars[i+1]){
                c++;
            }
            else{
                res++;
                chars[j++] = chars[i];
                string s = to_string(c);
                if(c>1){
                    for (char &x : s)
                    {
                        res++;
                        chars[j++] = x;
                    }
                }
                c = 1;
                chars[j] = chars[i+1];
            }
        }
        if(c>1){
            chars[j++] = chars[chars.size() - 1];
            string s = to_string(c);
            for (char &x : s)
            {
                res++;
                chars[j++] = x;
            }
        }
        return res;
    }
};