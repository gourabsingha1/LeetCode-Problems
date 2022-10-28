class SnapshotArray {
public:
    unordered_map<int, map<int,int>> nums;
    int snapId = 0;
    SnapshotArray(int length) {
        for (int i = 0; i < length; i++)
        {
            map<int,int> m;
            m[0] = 0;
            nums[i] = m;
        }
    }
    
    void set(int index, int val) {
        nums[index][snapId] = val;
    }
    
    int snap() {
        return snapId++;
    }
    
    int get(int index, int snap_id) {
        auto it = nums[index].upper_bound(snap_id);
        it--;
        return (*it).second;
    }
};