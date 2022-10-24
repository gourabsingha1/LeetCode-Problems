class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int high = numbers.size()-1, low = 0;
        while(low<high){
            if(numbers[low] + numbers[high] == target){
                return {low+1, high+1};
            }
            else if(numbers[low] + numbers[high] > target){
                high -= 1;
            }
            else{
                low += 1;
            }
        }
        return numbers;
    }
};