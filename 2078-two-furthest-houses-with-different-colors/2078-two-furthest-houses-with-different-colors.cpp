class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        if(colors[0] != colors.back()) {
            return n - 1;
        }

        int i = 0, j = colors.size() - 1;
        while(colors[0] == colors[j]) {
            j--;
        }
        while(colors[i] == colors[n - 1]) {
            i++;
        }
        return max(j, n - i - 1);
    }
};