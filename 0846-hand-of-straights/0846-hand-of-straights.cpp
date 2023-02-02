class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize) return 0;
        map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            m[hand[i]]++;
        }
        sort(hand.begin(), hand.end());
        for (int i = 0; i < n; i++)
        {
            if(!m[hand[i]]) continue;
            for (int j = 0; j < groupSize; j++)
            {
                if(!m[hand[i] + j]--) return 0;
            }
        }
        return 1;
    }
};