class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int res = 1, n = dist.size();
        vector<int> time(n);
        for (int i = 0; i < n; i++)
        {
            time[i] = (dist[i] + speed[i] - 1) / speed[i];
            cout<<time[i]<<' ';
        }
        cout<<endl;
        sort(time.begin(), time.end());
        for (int i = 1; i < n; i++)
        {
            if(time[i] - i - 1 < 0) {
                break;
            }
            res++;
        }
        return res;
    }
};