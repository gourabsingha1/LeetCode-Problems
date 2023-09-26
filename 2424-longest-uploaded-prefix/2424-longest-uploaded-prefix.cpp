class LUPrefix {
public:
    vector<int> nums;
    int n, longestInd = 0;

    LUPrefix(int n) {
        this->n = n;
        nums.resize(n, 0);
    }
    
    void upload(int video) {
        nums[video - 1] = 1;
        while(longestInd < n && nums[longestInd]) {
            longestInd++;
        }
    }
    
    int longest() {
        return longestInd;
    }
};