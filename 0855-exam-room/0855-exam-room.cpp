class ExamRoom {
public:
    set<int> st;
    int n;

    ExamRoom(int n) {
        this->n = n - 1;
    }
    
    int seat() {
        if(st.size() == 0) {
            st.insert(0);
            return 0;
        }

        // O(N) to find a nice option
        int res = 0, mx = 0;
        auto it = st.begin();
        it++;
        while(it != st.end()) {
            int cur = (*it - *prev(it)) / 2;
            if(mx < cur) {
                mx = cur;
                res = *prev(it) + cur;
            }
            it++;
        }

        // if front or back is a nice option
        int front = *st.begin();
        if(mx <= front) {
            mx = front;
            res = 0;
        }
        int back = n - *prev(st.end());
        if(mx < back) {
            res = n;
        }
        st.insert(res);
        return res;
    }
    
    void leave(int p) {
        st.erase(p);
    }
};