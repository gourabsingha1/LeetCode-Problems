class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> res, m(26, 0);
        int n = s.size(), currMax = 0;
        for (int i = 0; i < n; i++) m[s[i] - 'a'] = i;
        for (int i = 0; i < n; i++)
        {
            int size = 1;
            currMax = m[s[i] - 'a'];
            while(i < currMax){
                size++;
                i++;
                if(currMax < m[s[i] - 'a']){
                    currMax = m[s[i] - 'a'];
                }
            }
            res.push_back(size);
        }
        return res;
    }
};