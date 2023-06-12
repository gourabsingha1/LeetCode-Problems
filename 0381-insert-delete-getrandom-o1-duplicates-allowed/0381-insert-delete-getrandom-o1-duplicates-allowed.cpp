class RandomizedCollection {
public:
    vector<int> nums; // use set
    unordered_map<int, set<int>> mp; // num, indices (1 based)

    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        nums.push_back(val);
        mp[val].insert(nums.size());

        return mp[val].size() == 1;
    }
    
    bool remove(int val) {
        if(!mp[val].size()) {
            return 0;
        }

        int last = nums.back();
        auto it1 = prev(mp[val].end());
        int ind = *it1 - 1;
        mp[val].erase(it1); // remove operation
        nums[ind] = last; // swap(index(val), index(last))

        mp[last].insert(ind + 1); // update mp of last
        auto it2 = prev(mp[last].end());
        mp[last].erase(it2);

        nums.pop_back();

        return 1;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};