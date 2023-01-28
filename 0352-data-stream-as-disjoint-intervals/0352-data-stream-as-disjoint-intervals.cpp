class SummaryRanges {
public:
    set<int> st;
    void addNum(int value) {
        st.insert(value);
    }
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        for(auto &x : st){
            if(res.size() && res.back().back() + 1 == x){
                res.back().back() = x;
            }
            else{
                res.push_back({x,x});
            }
        }
        return res;
    }
};