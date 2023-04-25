class SmallestInfiniteSet {
public:
    set<int> st;
    int n;
    SmallestInfiniteSet() {
        n = 1;
    }
    
    int popSmallest() {
        if(st.size()) {
            int x = *st.begin();
            st.erase(x);
            return x;
        }
        return n++;
    }
    
    void addBack(int num) {
        if(num < n) {
            st.insert(num);
        }
    }
};