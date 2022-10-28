class Solution {
public:
    int minimumLength(string s) {
        int low = 0, high = s.size() - 1;
        while(low < high && s[low] == s[high]){
            if(low+1 < high && s[low] == s[low+1]){
                low++;
            }
            else if(low < high-1 && s[high] == s[high-1]){
                high--;
            }
            else if(s[low] == s[high]){
                low++;
                high--;
            }
        }
        return high - low + 1;
    }
};