class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> res;
        vector<pair<vector<int>, int>> temp;
        int n = tasks.size();
        for (int i = 0; i < n; i++)
        {
            temp.push_back(make_pair(tasks[i], i));
        }
        sort(temp.begin(), temp.end());

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> available;
        long long int time = temp[0].first[0], i = 0;
        int processingTime = temp[i].first[1], index = temp[i++].second;
        available.push({processingTime, index});

        while(available.size()){
            auto CPU = available.top();
            available.pop();
            time += CPU.first;
            for ( ; i < n && temp[i].first[0] <= time; i++)
            {
                processingTime = temp[i].first[1], index = temp[i].second;
                available.push({processingTime, index});
            }
            res.push_back(CPU.second);
            
            if(i<n && !available.size()){
                time = temp[i].first[0];
                processingTime = temp[i].first[1], index = temp[i].second;
                available.push({processingTime, index});
                i++;
            }
        }

        return res;
    }
};