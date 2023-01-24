class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();
        for (int i = 1; i < n; i++)
        {
            if(s[i - 1] < s[i]){
                char maxDigit = '0';
                int j = i, maxInd = i;
                while(j < n){
                    if(s[j] >= maxDigit){
                        maxDigit = s[j];
                        maxInd = j;
                    }
                    j++;
                }
                for (int k = 0; k < i; k++)
                {
                    if(s[k] < s[maxInd]){
                        swap(s[k], s[maxInd]);
                        return stoi(s);
                    }
                }
            }
        }
        return num;
    }
};