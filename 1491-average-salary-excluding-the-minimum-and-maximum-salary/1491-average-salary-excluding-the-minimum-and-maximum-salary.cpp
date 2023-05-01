class Solution {
public:
    double average(vector<int>& salary) {
        int n = salary.size(), minSalary = salary[0], maxSalary = salary[0], total = 0;
        for (int i = 0; i < n; i++)
        {
            minSalary = min(minSalary, salary[i]);
            maxSalary = max(maxSalary, salary[i]);
            total += salary[i];
        }
        return double (total - minSalary - maxSalary) / (n - 2);
    }
};