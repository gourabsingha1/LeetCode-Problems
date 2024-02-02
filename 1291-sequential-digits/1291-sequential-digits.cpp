// s = "123456789", try all substrings of size from lowSize to highSize

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        string s = "123456789";
        int lowSize = to_string(low).size(), highSize = to_string(high).size();
        for (int size = lowSize; size <= highSize; size++)
        {
            for (int i = 0; i + size <= 9; i++)
            {
                int num = stoi(s.substr(i, size));
                if(low <= num && num <= high) {
                    res.push_back(num);
                }
            }
        }
        return res;
    }
};