class Solution{
public:
    vector<vector<int>> generate(int numRows){
        vector<vector<int>> res;
        for (int i = 0; i < numRows; i++)
        {
            vector<int> temp(i + 1, 1);
            for (int j = 0; j < i / 2; j++)
            {
                temp[j + 1] = (res[i - 1][j] + res[i - 1][j + 1]);
                temp[i - j - 1] = temp[j + 1];
            }
            res.push_back(temp);
        }
        return res;
    }
};