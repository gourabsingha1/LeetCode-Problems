class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if(letters.back() <= target){
            return letters[0];
        }
        int low = 0, high = letters.size() - 1;
        while(low <= high){
            int mid = high + (low - high) / 2;
            if (letters[mid] > target){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return letters[low];
    }
};