class Solution {
public:
    int helper(int n, vector<int>& jobs, int& k, vector<int>& workers){
        if(n < 0){
            return *max_element(workers.begin(), workers.end());
        }

        int res = INT_MAX;
        for (int i = 0; i < k; i++)
        {
            if(i > 0 && workers[i - 1] <= workers[i]) continue;
            workers[i] += jobs[n];
            res = min(res, helper(n - 1, jobs, k, workers));
            workers[i] -= jobs[n];
        }
        return res;
    }

    int minimumTimeRequired(vector<int>& jobs, int k) {
        sort(jobs.begin(), jobs.end());
        int n = jobs.size();
        vector<int> workers(k, 0);
        return helper(n - 1, jobs, k, workers);
    }
};