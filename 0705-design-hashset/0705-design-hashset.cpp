class MyHashSet {
public:
    vector<bool> ms;
    
    MyHashSet() {
        ms.resize(1e6 + 1, 0);
    }
    
    void add(int key) {
        ms[key] = 1;
    }
    
    void remove(int key) {
        ms[key] = 0;
    }
    
    bool contains(int key) {
        return ms[key];
    }
};