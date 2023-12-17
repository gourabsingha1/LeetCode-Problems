#define ll long long

vector<ll> pals;

void findPals() {
    for (int i = 1; i < 10; i++)
    {
        // 1, 2 digits
        string s = to_string(i), p = s;
        pals.push_back(stoll(s + p));
        s.pop_back();
        pals.push_back(stoll(s + p));
        for (int j = 0; j < 10; j++)
        {
            // 3, 4 digits
            s = to_string(i) + to_string(j), p = s;
            reverse(p.begin(), p.end());
            pals.push_back(stoll(s + p));
            s.pop_back();
            pals.push_back(stoll(s + p));
            for (int k = 0; k < 10; k++)
            {
                // 5, 6 digits
                s = to_string(i) + to_string(j) + to_string(k), p = s;
                reverse(p.begin(), p.end());
                pals.push_back(stoll(s + p));
                s.pop_back();
                pals.push_back(stoll(s + p));
                for (int l = 0; l < 10; l++)
                {
                    // 7, 8 digits
                    s = to_string(i) + to_string(j) + to_string(k) + to_string(l), p = s;
                    reverse(p.begin(), p.end());
                    pals.push_back(stoll(s + p));
                    s.pop_back();
                    pals.push_back(stoll(s + p));
                    for (int m = 0; m < 10; m++)
                    {
                        // 9 digit
                        s = to_string(i) + to_string(j) + to_string(k) + to_string(l) + to_string(m), p = s;
                        reverse(p.begin(), p.end());
                        s.pop_back();
                        pals.push_back(stoll(s + p));
                    }
                }
            }
        }
    }
    sort(pals.begin(), pals.end());
}

class Solution {
public:
    Solution() {
        if(pals.size() == 0) {
            findPals();
        }
    }

    long long minimumCost(vector<int>& nums) {
        ll cost = 1e14, low = 0, high = pals.size() - 1;
        while(low <= high) {
            ll mid = (low + high) / 2;
            ll cur = 0;
            for(auto& c : nums) {
                cur += abs(pals[mid] - c);
            }
            ll cur2 = 1e14;
            if(mid + 1 < pals.size()) {
                cur2 = 0;
                for(auto& c : nums) {
                    cur2 += abs(pals[mid + 1] - c);
                }
            }
            if(cur <= cur2) {
                cost = min(cost, cur);
                high = mid - 1;
            }
            else {
                low = mid + 1;
                cost = min(cost, cur2);
            }
        }
        return cost;
    }
};