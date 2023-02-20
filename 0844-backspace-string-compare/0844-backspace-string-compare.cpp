class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1, j = t.size() - 1;
        while(i >= 0 && j >= 0){
            while(i >= 0 && s[i] == '#'){
                int sHash = 1;
                i--;
                while(i >= 0 && sHash){
                    if(s[i--] == '#'){
                        sHash++;
                    }
                    else{
                        sHash--;
                    }
                }
            }
            while(j >= 0 && t[j] == '#'){
                int tHash = 1;
                j--;
                while(j >= 0 && tHash){
                    if(t[j--] == '#'){
                        tHash++;
                    }
                    else{
                        tHash--;
                    }
                }
            }
            if(i >= 0 && j >= 0 && s[i] != t[j] || i >= 0 && j < 0 || i < 0 && j >= 0){
                return 0;
            }
            i--, j--;
        }
        if(i >= 0){
            int sHash = 0;
            while(i >= 0){
                if(s[i--] == '#'){
                    sHash++;
                }
                else{
                    sHash--;
                }
            }
            return sHash >= 0;
        }
        else if(j >= 0){
            int tHash = 0;
            while(j >= 0){
                if(t[j--] == '#'){
                    tHash++;
                }
                else{
                    tHash--;
                }
            }
            return tHash >= 0;
        }
        return 1;
    }
};