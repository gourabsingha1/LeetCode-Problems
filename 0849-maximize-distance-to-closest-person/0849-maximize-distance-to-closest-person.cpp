// store the index of the elements that are 1 in the set
// whenever we come across 0 find the lower and upper bound and correspondingly store the maximum distance to the closest person

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int res = 1, n = seats.size();
        set<int> st;
        for (int i = 0; i < n; i++)
        {
            if(seats[i]) {
                st.insert(i);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if(seats[i] == 0) {
                auto lb = st.lower_bound(i);
                int lbVal = n;
                if(lb != st.begin()) {
                    lbVal = i - *(--lb);
                }

                auto ub = st.upper_bound(i);
                int ubVal = n;
                if(ub != st.end()) {
                    ubVal = *ub - i;
                }
                res = max(res, min(lbVal, ubVal));
            }
        }
        return res;
    }
};