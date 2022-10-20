class Solution {
public:
    string intToRoman(int num) {
        unordered_map<char,int> m;
        string ans;
        int j = 0;
        vector<char> a = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        while(num){
            int rem = num%10;
            if(rem==4){
                ans+=a[j+1];
                ans+=a[j];
                j+=2;
            }
            else if(rem==9){
                ans+=a[j+2];
                ans+=a[j];
                j+=2;
            }
            else{
                for (int i = 0; i < rem%5; i++)
                {
                    ans+=a[j];
                }
                j++;
                for (int i = 0; i < rem/5; i++)
                {
                    ans+=a[j];
                }
                j++;
            }
            num/=10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};