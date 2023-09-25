// similar to pascals triangle
// child glass gets half of (parent glass - 1). parent keeps 1

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> prevRow = {(double)poured};
        for (int i = 1; i <= query_row; i++)
        {
            vector<double> curRow(i + 1);
            for (int j = 1; j < curRow.size(); j++)
            {
                if(prevRow[j - 1] < 1) continue;
                double half = (prevRow[j - 1] - 1.0) / 2.0;
                curRow[j - 1] += half, curRow[j] += half, prevRow[j - 1] = 1;
            }
            prevRow = curRow;
        }
        return min(1.0, max(0.0, prevRow[query_glass]));
    }
};