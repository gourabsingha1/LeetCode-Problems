class NumberContainers {
public:
    unordered_map<int, set<int>> mp; // number, indices
    unordered_map<int, int> indNum; // index, number

    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        int prevNum = indNum[index];
        if(prevNum) {
            mp[prevNum].erase(mp[prevNum].find(index));
        }
        mp[number].insert(index);
        indNum[index] = number;
    }
    
    int find(int number) {
        if(mp[number].size() == 0) {
            return -1;
        }
        return *mp[number].begin();
    }
};