#define ll long long

vector<ll> pals;

void findPals() {
    // 1, 2 digits
    for (int i = 1; i < 10; i++)
    {
        string s = to_string(i);
        string p = s;
        reverse(p.begin(), p.end());
        pals.push_back(stoll(s + p));
        s.pop_back();
        pals.push_back(stoll(s + p));
    }
    
    // 3, 4 digits
    for (int i = 1; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            string s = to_string(i) + to_string(j);
            string p = s;
            reverse(p.begin(), p.end());
            pals.push_back(stoll(s + p));
            s.pop_back();
            pals.push_back(stoll(s + p));
        }
    }
    
    // 5, 6 digits
    for (int i = 1; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                string s = to_string(i) + to_string(j) + to_string(k);
                string p = s;
                reverse(p.begin(), p.end());
                pals.push_back(stoll(s + p));
                s.pop_back();
                pals.push_back(stoll(s + p));
            }
        }
    }
    
    // 7, 8 digits
    for (int i = 1; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                for (int l = 0; l < 10; l++)
                {
                    string s = to_string(i) + to_string(j) + to_string(k) + to_string(l);
                    string p = s;
                    reverse(p.begin(), p.end());
                    pals.push_back(stoll(s + p));
                    s.pop_back();
                    pals.push_back(stoll(s + p));
                }
            }
        }
    }
    
    // 9 digits
    for (int i = 1; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                for (int l = 0; l < 10; l++)
                {
                    for (int m = 0; m < 10; m++)
                    {
                        string s = to_string(i) + to_string(j) + to_string(k) + to_string(l) + to_string(m);
                        string p = s;
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
        // sort(nums.begin(), nums.end());
        // unordered_map<ll, int> mp;
        // int n = nums.size();
        // for (int i = 0; i < n; i++)
        // {
        //     mp[nums[i]] = i;
        // }
        // vector<int> pre(n), suf(n);
        // pre[0] = nums[0];
        // suf[n - 1] = nums[n - 1];
        // for (int i = 1; i < n; i++)
        // {
        //     pre[i] = nums[i] + pre[i - 1];
        //     suf[n - 1 - i] = nums[n - 1 - i] + suf[n - i];
        // }

        ll cost = 1e14;
        // for(auto& x : pals) {
        //     if(x > nums.back()) break;
        //     auto ub = upper_bound(nums.begin(), nums.end(), x);
        //     ub--;
        //     int i = mp[*ub];
        //     cout<<i<<' ';
        //     if(i == 0 && *ub != nums[i]) break;
        //     ll cur = (1LL * x * (i + 1) - pre[i]) + (suf[i] - 1LL * x * (n - i));
        //     cost = min(cost, cur);
        // }
        // cout<<endl;
        
        
        // for(auto& x : pals) {
        //     ll cur = 0;
        //     for(auto& c : nums) {
        //         cur += abs(x - c);
        //     }
        //     cost = min(cost, cur);
        // }
        ll low = 0, high = pals.size() - 1;
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