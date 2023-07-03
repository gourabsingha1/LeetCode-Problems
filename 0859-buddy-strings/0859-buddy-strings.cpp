class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size() != goal.size()) {
            return 0;
        }

        vector<int> mp(26, 0);
        bool same = 0;
        string newS, newGoal;
        for (int i = 0; i < s.size(); i++)
        {
            if(s[i] != goal[i]) {
                newS += s[i];
                newGoal += goal[i];
            }
            if(mp[s[i] - 'a']) {
                same = 1;
            }
            mp[s[i] - 'a']++;
        }
        return newS.size() == 2 && newS[0] == newGoal[1] && newS[1] == newGoal[0] || newS.size() == 0 && same;
    }
};