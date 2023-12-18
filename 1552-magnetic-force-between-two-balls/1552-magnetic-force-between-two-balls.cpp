// wubba lubba dub dub
// binary search on answer
// dry run on [1,2,3,4,7,8,9,11,35,44,45,23], m = 5
// always place one ball on first position, thats why m - 1

class Solution {
public:
    bool isPossible(int force, vector<int>& position, int m) {
        int last = position[0];
        while(m > 0) {
            auto lb = upper_bound(position.begin(), position.end(), last + force);
            if(lb != position.end()) {
                m--;
                last = *lb;
            }
            else {
                return 0;
            }
        }
        return 1;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int low = 1, high = position.back();
        while(low <= high) {
            int force = (low + high) / 2;
            if(isPossible(force, position, m - 1)) {
                low = force + 1;
            }
            else {
                high = force - 1;
            }
        }
        return low;
    }
};