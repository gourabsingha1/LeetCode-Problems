class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 0, j = 0;
        for(auto& x : pushed) {
            pushed[i] = x;
            while(i >= 0 && pushed[i] == popped[j]) {
                i--, j++;
            }
            i++;
        }
        return i == 0;
    }
};