// lower_bound(num) in set returns iterator where *it >= num

class MyCalendar {
public:
    set<pair<int, int>> st;
    
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto lb = st.lower_bound({start, end});
        if(lb != st.begin() && start < prev(lb)->second) {
            return 0;
        }
        if(lb != st.end() && end > lb->first) {
            return 0;
        }
        st.insert({start, end});
        return 1;
    }
};