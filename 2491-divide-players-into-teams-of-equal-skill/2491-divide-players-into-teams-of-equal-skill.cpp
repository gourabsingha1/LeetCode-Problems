class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int n = skill.size(), c = skill[0] + skill[n-1];
        long long res = skill[0] * skill[n-1];
        for (int i = 1; i < n/2; i++)
        {
            if(skill[i] + skill[n-1-i] != c) return -1;
            res += skill[i] * skill[n-1-i];
        }
        return res;
    }
};