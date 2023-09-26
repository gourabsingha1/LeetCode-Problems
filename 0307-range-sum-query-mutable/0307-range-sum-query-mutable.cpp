// **** Segment Trees - O(N), O(N) ****
class NumArray {
public:
    vector<int> a, seg, lazy;
    NumArray(vector<int>& a) {
        this->a = a;
        seg.resize(4 * a.size());
        build(0, 0, a.size() - 1);
    }

    // build the segment tree - O(N)
    void build(int ind, int low, int high) {
        if(low == high) {
            seg[ind] = a[low];
            return;
        }

        int mid = (low + high) / 2;
        int left = 2 * ind + 1, right = 2 * ind + 2;
        build(left, low, mid);
        build(right, mid + 1, high);
        // seg[ind] = max(seg[left], seg[right]);
        // find the minimum value
        // seg[ind] = min(seg[left], seg[right]);
        // find the sum
        seg[ind] = seg[left] + seg[right];
    }

    // query to find min/max/sum in range (l, r) - O(logN)
    int query(int ind, int low, int high, int l, int r) {
        // completely lies
        if(l <= low && r >= high) {
            return seg[ind];
        }
        // doesn't lie
        if(l > high || r < low) {
            // return INT_MIN;
            // find the minimum value
            // return INT_MAX;
            // find the sum
            return 0;
        }

        // overlaps
        int mid = (low + high) / 2;
        int leftQuery = query(2 * ind + 1, low, mid, l, r);
        int rightQuery = query(2 * ind + 2, mid + 1, high, l, r);
        // return max(leftQuery, rightQuery);
        // find the minimum value
        // return min(leftQuery, rightQuery);
        // find the sum
        return leftQuery + rightQuery;
    }

    // single element update with val - O(logN)
    void pointUpdate(int ind, int low, int high, int index, int val) {
        if(low == high) {
            seg[ind] = val;
        }
        else {
            int mid = (low + high) / 2;
            int left = 2 * ind + 1, right = 2 * ind + 2;
            if(low <= index && index <= mid) {
                pointUpdate(left, low, mid, index, val);
            }
            else {
                pointUpdate(right, mid + 1, high, index, val);
            }
            seg[ind] = seg[left] + seg[right];
        }
    }

    // update all values in range (l, r) with val - O(logN)
    void rangeUpdate(int ind, int low, int high, int l, int r, int val) {
        int left = 2 * ind + 1, right = 2 * ind + 2;
        if(lazy[ind]) {
            seg[ind] += (high - low + 1) * lazy[ind];
            if(low != high) {
                lazy[left] += lazy[ind];
                lazy[right] += lazy[ind];
            }
            lazy[ind] = 0;
        }
        if(l > high || r < low || low > high) {
            return;
        }
        if(l <= low && r >= high) {
            seg[ind] += (high - low + 1) * val;
            if(low != high) {
                lazy[left] += lazy[ind];
                lazy[right] += lazy[ind];
            }
            return;
        }

        int mid = (low + high) / 2;
        rangeUpdate(left, low, mid, l, r, val);
        rangeUpdate(right, mid + 1, high, l, r, val);
        seg[ind] = seg[left] + seg[right];
    }

    // query to find sum in lazy in range (l, r) - O(logN)
    int querySumLazy(int ind, int low, int high, int l, int r, int val) {
        int left = 2 * ind + 1, right = 2 * ind + 2;
        if(lazy[ind]) {
            seg[ind] += (high - low + 1) * lazy[ind];
            if(low != high) {
                lazy[left] += lazy[ind];
                lazy[right] += lazy[ind];
            }
            lazy[ind] = 0;
        }
        if(l > high || r < low || low > high) {
            return 0;
        }
        if(l <= low && r >= high) {
            return seg[ind];
        }

        int mid = (low + high) / 2;
        return querySumLazy(left, low, mid, l, r, val) + querySumLazy(right, mid + 1, high, l, r, val);
    }


    void update(int index, int val) {
        pointUpdate(0, 0, a.size() - 1, index, val);
    }

    int sumRange(int left, int right) {
        return query(0, 0, a.size() - 1, left, right);
    }
};