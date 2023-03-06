class Solution {
public:
    string numberToWords(int num) {
        if(num == 0){
            return "Zero";
        }
        string res;
        vector<string> ones = {"One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine "};
        vector<string> tens = {"Ten ", "Eleven ", "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen "};
        vector<string> hundreds = {"Ten ", "Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety "};
        string s = to_string(num);
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            int j = n - i, ind = s[i] - '0' - 1;
            // if(ind < 0 && j != 4) continue;
            if(ind >= 0 && j % 3 == 2){
                if(s[i] == '1'){
                    res += tens[s[i + 1] - '0'];
                    i++, j--;
                }
                else{
                    res += hundreds[ind];
                }
            }
            else if(ind >= 0){
                res += ones[ind];
            }

            if(j % 3 == 0 && s[i] > '0'){
                res += "Hundred ";
            }
            else if(j == 10){
                res += "Billion ";
            }
            else if(j == 7 && (s[i] > '0' || i - 1 >= 0 && s[i - 1] > '0' || i - 2 >= 0 && s[i - 2] > '0')){
                res += "Million ";
            }
            else if(j == 4 && (s[i] > '0' || i - 1 >= 0 && s[i - 1] > '0' || i - 2 >= 0 && s[i - 2] > '0')){
                res += "Thousand ";
            }
        }
        res.pop_back();
        return res;
    }
};