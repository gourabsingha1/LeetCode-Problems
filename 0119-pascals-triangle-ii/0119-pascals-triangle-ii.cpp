class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        for (int i = 0; i <= rowIndex; i++)
        {
            vector<int> temp(i + 1, 1);
            for (int j = 0; j < i / 2; j++)
            {
                temp[j + 1] = res[j] + res[j + 1];
                temp[i - j - 1] = temp[j + 1];
            }
            res = temp;
        }
        return res;
    }
};