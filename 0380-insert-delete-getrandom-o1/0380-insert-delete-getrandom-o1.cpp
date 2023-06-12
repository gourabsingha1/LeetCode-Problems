class RandomizedSet {
public:
    vector<int> nums;
    unordered_map<int, int> mp; // num, index (1 based)

    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp[val]) {
            return 0;
        }

        nums.push_back(val);
        mp[val] = nums.size();

        return 1;
    }
    
    bool remove(int val) {
        if(!mp[val]) {
            return 0;
        }

        int last = nums.back();
        int ind = mp[val] - 1;
        nums[ind] = last;
        mp[last] = mp[val];
        mp[val] = 0;
        nums.pop_back();

        return 1;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};