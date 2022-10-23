class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res, prev;
        for (int i = 0; i <= rowIndex; i++)
        {
            vector<int> v(i+1,1);
            for (int j = 0; j < i/2; j++)
            {
                v[j+1] = (prev[j] + prev[j+1]);
                v[i - j - 1] = v[j+1];
            }
            prev = v;
        }
        return prev;
    }
};